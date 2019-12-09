import socket
import json

#clientsocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#clientsocket.connect(('localhost', 8026))

msg_type = '101'
data = {
	'_username' : 'o',
	'_password' : 'o555'
}

try:
	serialized = json.dumps(data)
	size = len(serialized)
except(TypeError, ValueError) as e:
	raise Exception('You can only send JSON-serializable data')
print(serialized)		
'''
msg = msg_type+str(size)+serialized
#send the Length & Code of the serialized data first

clientsocket.sendall(msg.encode())

ans = clientsocket.recv(1024).decode()
print(ans)
#########################################

room_data = {
	'room_name' : 'my_room',
	'max_users' : 3,
	'question_count' : 2,
	'answer_timeout' : 10
}
msg_type = '108'
str_room_data = json.dumps(room_data)
msg = msg_type+str(len(str_room_data))+str_room_data

clientsocket.sendall(msg.encode())
ans = clientsocket.recv(2056).decode()
print(ans)
msg_type = '107'
room_id = {
	'room_id' : 1
}
str_room_id = json.dumps(room_id)
msg = msg_type+str(len(str_room_id))+str_room_id
clientsocket.sendall(msg.encode())
ans = clientsocket.recv(2056).decode()
print(ans)

msg_type = '111'
msg = msg_type+ str(0)
clientsocket.sendall(msg.encode())
ans = clientsocket.recv(2056).decode()
print(ans)

msg_type = '-1'
msg = msg_type
clientsocket.sendall(msg.encode())	
clientsocket.close()
'''