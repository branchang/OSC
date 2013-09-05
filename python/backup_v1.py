#!/usr/bin/python
#filename:backup_ver1.py

import os
import time

# Need backup file and dir 
source = ['/home/Bran/Public', '/home/Bran/Notes', '/home/Bran/Documents']

#backup xxxxxx.zip file stroe path
target_dir = '/home/Bran/Backup/'

#file name of zip archive is current date and time
today = target_dir + time.strftime('%Y%m%d')

now = time.strftime('%H%M%S') 

if not os.path.exists(today):
    os.mkdir(today)
    print 'Successfully create dir', today

target = today + os.sep + now + '.tar.gz'

#we ues the zip command to put the files in a zip archive
#zip_command = "zip -qr '%s' %s" % (target, ' '.join(source))
tar_command = "tar -cvzf '%s' %s "% (target, ' '.join(source)) 

if os.system(tar_command) == 0:
    print "Sunncess backupto", target
else:
    print "Back up FAILED"
