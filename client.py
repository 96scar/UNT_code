import socket
import sys

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print 'Created socket'

server_address = ('cse04.cse.unt.edu', 2048)
sock.connect(server_address)
print 'Connected to server'

message = sock.recv(1024)
print 'Received a message: ' + message
if message == 'bye':
	sock.close()
	sys.exit()
message = 'This is the message.\n\r'
sock.sendall(message)
print 'Sent the message: ' + message

message = sock.recv(1024)
print 'Received a message: ' + message

sock.close()
