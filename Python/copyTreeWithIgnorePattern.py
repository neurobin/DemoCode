import os,sys,shutil
ignoreDirPatterns=[".git"]
ignoreFilePatterns=[]
def copyTree(src, dest, onerror=None):
    src = os.path.abspath(src)
    src_prefix = len(src) + len(os.path.sep)
    for root, dirs, files in os.walk(src, onerror=onerror):
        for pattern in ignoreDirPatterns:
            if pattern in root:
                break
        else:
            #If the above break didn't work, this part will be executed
            for file in files:
                for pattern in ignoreFilePatterns:
                    if pattern in file:
                        break
                else:
                    #If the above break didn't work, this part will be executed
                    dirpath = os.path.join(dest, root[src_prefix:])
                    try:
                        os.makedirs(dirpath,exist_ok=True)
                    except OSError as e:
                        if onerror is not None:
                            onerror(e)
                    filepath=os.path.join(root,file)
                    shutil.copy(filepath,dirpath)
                continue;#If the above else didn't executed, this will be reached
            
        continue;#If the above else didn't executed, this will be reached
        
