#!/bin/sh

set -e
dist="stretch"
arch="amd64"
extracted="extracted"
label="Debialin"
origin="Debian"
components="main"
suit="$dist"
override="$dist"

help="
Options:
	-d , --dist 	:	dist [$dist]
	-a, --arch	:	architecture [$arch]
	-t, --target	:	targent directory [$extracted]
	-l, --label	:	label [$label]
	-o, --origin	:	origin [$origin]
	-c, --components:	components [$components]
	-s, --suit	:	suit [$suit]
	-ov, --override	:	override [$override]
	-h, --help	:	help menu
"

while [ $# -gt 0 ]
do
    case "$1" in
    	-d|--dist)
		shift
    		dist="${1-$dist}"
    		;;
        -a|--arch)
		shift
        	arch="${1-$arch}"
            ;;
        -t|--target)
		shift
        	extracted="${1-$extracted}"
            ;;
	-l|--label)
		shift
		label="${1-$label}"
            ;;
	-o|--origin)
		shift
		origin="${1-$origin}"
            ;;
	-c|--components)
		shift
		components="${1-$components}"
            ;;
	-s|--suit)
		shift
		suit="${1-$suit}"
		;;
	-ov|--override)
		shift
		override="$1" #can be empty
		;;
        -h|--help|*)
            echo "$help"
            exit 0
            ;;
    esac
    shift
done

if [ "$override" = "" ]; then
	override="$dist"
fi

override_url=http://ftp.de.debian.org/debian/indices/override.$override.main.gz

cachedir=updaterp.cache

mkdir -p "$cachedir"

wget -c "$override_url" -O - | gunzip --stdout > "$cachedir"/override

config_common='
 Dir {
    ArchiveDir "'$extracted'";
    OverrideDir "'$cachedir'";
    CacheDir "'$cachedir'";
 };
            
 TreeDefault {
    Directory "pool/";
 };
'

config_deb_tmp="$cachedir/config-deb"
cat > "$config_deb_tmp" <<EOF
$config_common

 BinDirectory "pool/main" {
    Packages "dists/$dist/main/binary-$arch/Packages";
    BinOverride "override";
 };
                                   
 Default {
    Packages {
        Extensions ".deb";
    };
 };
EOF

config_udeb_tmp="$cachedir/config-udeb"
cat > "$config_udeb_tmp"<<EOF
$config_common
                    
 BinDirectory "pool/main" {
    Packages "dists/$dist/main/debian-installer/binary-$arch/Packages";
    BinOverride "override";
 };
                                   
 Default {
    Packages {
        Extensions ".udeb";
    };
 };
EOF

config_rel="$cachedir/config-release"

cat > "$config_rel" <<EOF
APT::FTPArchive::Release::Codename "$dist";
APT::FTPArchive::Release::Origin "$origin";
APT::FTPArchive::Release::Components "$components";
APT::FTPArchive::Release::Label "$label";
APT::FTPArchive::Release::Architectures "$arch";
APT::FTPArchive::Release::Suite "$suit";
EOF

apt-ftparchive generate "$config_deb_tmp"
apt-ftparchive generate "$config_udeb_tmp"
apt-ftparchive -c "$config_rel" release "$extracted/dists/$dist" > "extracted/dists/$dist/Release"


