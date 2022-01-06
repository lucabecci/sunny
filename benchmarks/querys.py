import socket
import sys
import uuid
from random import seed
from random import random
import time

import asyncio

seed(1)
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

def bench():
    arr = []
    values = []
    print("Bench started")
    connection()
    for x in range(40):
        v = str(uuid.uuid4())
        arr.append(v)
        t = str(random())
        values.append(t)
        query_put = 'put ' + v + " " + t
        print("Inserted " + query_put)
        sock.send(query_put.encode("utf-8"))
        time.sleep(0.05)
    return

def connection():
    server_address = ('localhost', 8080)
    print('connecting to {} port {}'.format(*server_address))
    sock.connect(server_address)


bench()