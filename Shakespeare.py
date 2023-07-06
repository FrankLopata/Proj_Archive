import socket
import random
if __name__ == '__main__':
    sock = socket.socket()
    connect_adress = ('circinus-32.ics.uci.edu', 1564)
    sock.connect(connect_adress)
    input_stream = sock.makefile('r')
    output_stream = sock.makefile('w')

    output_stream.write("SHAKESPEARE_COUNTS\r\n")
    output_stream.flush()
    #delete this ^
    x = input_stream.readline()
    op = x.split()
    index = 0
    while index < len(op):
        op[index] = int(op[index])
        op[index] = random.randrange(0,op[index])
        op[index] = str(op[index])
        index = index + 1

    
    output_stream.write("SHAKESPEARE_INSULT " + op[0] + " " + op[1] + " " + op[2]+ "\r\n")              
    output_stream.flush()
    print(input_stream.readline())

    output_stream.write("SHAKESPEARE_GOODBYE\r\n")
    output_stream.flush()
    print(input_stream.readline())

    input_stream.close()
    output_stream.close()

