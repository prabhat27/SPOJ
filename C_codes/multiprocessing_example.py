import requests
import csv
import traceback
from multiprocessing import Pool,Manager
import os

headers  ={'User-Agent':'Mozilla/5.0 (Windows NT 6.1; WOW64; rv:19.0) Gecko/20100101 Firefox/27.0'}

def download(files,start_index,end_index):
    csv_data=files
    for i in range(len(csv_data)):  ##Iterated over the tickers to download 
        print str(i)+" :Ticker is :"+str(csv_data[i][0])
        if (os.path.isfile("data//history_csv//yahoo_finance//"+str(csv_data[i][0])+".csv")==False): ## Ignore ticker if data already extracted 
            try:
                url="http://ichart.finance.yahoo.com/table.csv?g=d&f=2014&e=31&c=2014&b=NaN&a=0&d=11&s="+str(csv_data[i][0]) #Created link for the download of the chosen ticker
                r = requests.get(url, stream=True,headers=headers)
                with open("data//history_csv//yahoo_finance//"+str(csv_data[i][0])+".csv", 'wb') as f:  ## Saved the file using name of the ticker
                    for chunk in r.iter_content(chunk_size=1024): 
                        if chunk: # filter out keep-alive new chunks
                            f.write(chunk)
                            f.flush()
            except Exception,e:
                fp=open("error25march.txt","a")   ## the error while downloading tickers are written 
                fp.write(str(csv_data[i][0])+'\n')
                fp.close()
                traceback.print_exc()
        else:
            print "already here !!!"

    
if __name__=='__main__':

    csv_data=list(csv.reader(file('.\\raw_data\\stock_ticker_list.csv','rU'))) 
    csv_data=csv_data[1:]
    total_process=1
    pool=Pool(total_process)
    total_files=len(csv_data)
    each_slot=total_files/total_process
    start_index=0
    end_index=0
    manager=Manager()
    queue=manager.Queue()
    for i in range(total_process):
        end_index+=each_slot
        if i==total_process-1:
            end_index=total_files
        try:
            flist=csv_data[start_index:end_index]
            print pool.apply_async(download,(flist,start_index,end_index))
        except Exception,e:
            traceback.print_exc()
        start_index+=each_slot
    
    pool.close()
    pool.join()
    print "done All!!!"


#return local_filename
