import socket
import sys


serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serversocket.bind((socket.gethostbyname('cse01.cse.unt.edu'), 2048))
serversocket.listen(10)
(clientsocket, address) = serversocket.accept()
print('Connected with: ' + str(address))
data = clientsocket.recv(1024)
data = data.strip()
print('Received: ' + data)
clientsocket.close()
serversocket.close()