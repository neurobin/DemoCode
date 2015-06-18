ignorePatterns=[".git"]
def createEmptyTree(src, dest):
    src_prefix = len(src) + len(os.path.sep)
    for root, dirs, files in os.walk(src):
        for pattern in ignorePatterns:
            if pattern in root:
                break
        else:
            #If the above break didn't work, this part will be executed
            for dirname in dirs:
                for pattern in ignorePatterns:
                    if pattern in dirname:
                        break
                else:
                    #If the above break didn't work, this part will be executed
                    dirpath = os.path.join(dest, root[src_prefix:], dirname)
                    try:
                        os.makedirs(dirpath,exist_ok=True)
                    except OSError as e:
                        print("Error: Couldn't create directory"+dirpath)
                continue;#If the above else didn't executed, this will be reached
            
        continue;#If the above else didn't executed, this will be reached
