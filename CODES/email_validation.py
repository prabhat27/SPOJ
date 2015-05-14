import csv
import re

writer=csv.writer(open("output.csv","ab"))

p=re.compile("(?:[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*@(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?)")
fp =open("input.txt","rU")
lines=fp.readlines()
i=1
for each in lines:
    txt=str(each).strip(" \n\t\r")
    txt=txt.lower()
    x = p.findall(txt)
    if x==None:
        print str(txt)
    else:
        #print x
        for a in x:
        	writer.writerow([a,])
        
    i+=1

print "done!!!"


