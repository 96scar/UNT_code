'''
    Simple socket server using threads
'''
 
import socket
import sys
from thread import *
 
HOST = 'cse04.cse.unt.edu'   # Symbolic name meaning all available interfaces
PORT = 2048 # Arbitrary non-privileged port
 
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print 'Socket created'
 
#Bind socket to local host and port
try:
    s.bind((HOST, PORT))
except socket.error as msg:
    print 'Bind failed. Error Code : ' + str(msg[0]) + ' Message ' + msg[1]
    sys.exit()
     
print 'Socket bind complete'
 
#Start listening on socket
s.listen(10)
print 'Socket now listening'
 
#Function for handling connections. This will be used to create threads
def clientthread(conn):
    #Sending message to connected client
    welcome = 'Welcome to the server.'
    welcome = 'bye'
    conn.send(welcome) #send only takes string
    print 'Sent a message: ' + welcome
    #infinite loop so that function do not terminate and thread do not end.
    while True:
        #Receiving from client
        data = conn.recv(1024)
	print 'Received a message: ' + data
        reply = 'OK...' + data
        if not data: 
            break
     
        conn.sendall(reply)
	print 'Send a message: ' + reply
     
    #came out of loop
    conn.close()

#Function for server to listen on
#def serverthread(s):
#	while True:
#		#wait to accept connection - blocking call
#		(conn, addr) = s.accept()
#		print 'Connected with ' + addr[0] + ':' + str(addr[1])
#		#start new thread
#		start_new_thread(clientthread, (conn, ))
#	s.close()
 
#now keep talking with the client
#while 1:
#	start_new_thread(serverthread, (s, ))
while 1:
    #wait to accept a connection - blocking call
    (conn, addr) = s.accept()
    print 'Connected with ' + addr[0] + ':' + str(addr[1])     
    #start new thread takes 1st argument as a function name to be run, second is the tuple of arguments to the function.
    start_new_thread(clientthread, (conn, ))
s.close()
