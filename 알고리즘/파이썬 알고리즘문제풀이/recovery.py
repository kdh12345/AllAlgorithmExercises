import sys
import os
import time
import shutil
import magic

 
# Referenced from "https://wikidocs.net/39"
def search(dirname):
    filenames = os.listdir(dirname)
    for filename in filenames:
        full_filename = os.path.join(dirname, filename)
        if os.path.isdir(full_filename):
            search(full_filename)
        else:
            path = time.strftime("%Y.%m.%d" , time.localtime(os.path.getmtime(full_filename)))
            extention = magic.from_file(full_filename, mime=True).split("/")[1]
            
            if not os.path.exists("./result/" + path):
                os.mkdir("./result/" + path)
 
            shutil.copy(full_filename, "./result/" + path + "/" + filename + "." + extention)     
 
if not os.path.exists("result"):
    os.mkdir("result")
 
search("/mnt/g/com.kakao.talk/contents")