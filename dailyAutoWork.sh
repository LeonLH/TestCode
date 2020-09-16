#!/bin/bash

####################################################################
# Script Name	: 
# Description	: 
# Args			: 
# Author		: Leon Cheng
# Email			: laohan1221@gmail.com
####################################################################

PATH=/bin:/sbin/:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
LOGFILE=/home/leon/log/daily.log
export LOGFILE
export PATH

DATE=`date +%Y-%m-%d\ %H:%M:%S`
cd /home/leon/workspace/test/

echo 'cd /home/leon/workspace/test/' >> $LOGFILE
echo $DATE >> $LOGFILE 
echo "git add ." >> $LOGFILE
git add . &>> $LOGFILE 
echo "git commit -m 'daily upload testfile'" >> $LOGFILE
git commit -m "daily upload testfile" &>> $LOGFILE 
echo $DATE >> $LOGFILE 
echo "git push" >> $LOGFILE
git push &>> $LOGFILE 


cd /home/leon/workspace/WorkLog/CL
echo 'cd /home/leon/workspace/WorkLog/CL' >> $LOGFILE
echo $DATE >> $LOGFILE 
echo "git add ." >> $LOGFILE
git add . &>> $LOGFILE 
echo "git commit -m 'daily upload testfile'" >> $LOGFILE
git commit -m "daily upload worklog" &>> $LOGFILE 
echo $DATE >> $LOGFILE 
echo "git push" >> $LOGFILE
git push &>> $LOGFILE 

echo -e "\n\n" >> $LOGFILE
