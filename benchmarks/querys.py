import socket
import sys
import uuid
from random import seed
import random
import time


seed(1)
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

def bench():
    arr = []
    print("Bench started")
    connection()
    for x in range(500000):
        v = str(uuid.uuid4())
        arr.append(v)
        t = str(random.random())
        query_put = 'put ' + v + " " + t
        print("Inserted " + query_put)
        sock.send(query_put.encode("utf-8"))
        time.sleep(0.02)
    
    index = random.choice(arr)
    query = "get " + index
    start_time = time.time()
    sock.send(query.encode())
    data = sock.recv(1024)
    print("VALUE: " + data.decode())
    print("TIME TO FIND THE KEY IN THE DB")
    print("--- %s seconds ---" % (time.time() - start_time))

def connection():
    server_address = ('localhost', 8080)
    print('connecting to {} port {}'.format(*server_address))
    sock.connect(server_address)


bench()