//Laptop
#include <stdio.h>
#include <string.h>
#include <zmq.hpp>
#include <iostream>

using namespace std;

void * context; //Global context, because you only need one !

int main( int argc, char * argv[] )
{
    printf("Started\n");
    zmq::context_t ctx;

    zmq::socket_t pusher(ctx, zmq::socket_type::push);
    zmq::socket_t subscriber(ctx, zmq::socket_type::sub);

    pusher.connect("tcp://benternet.pxl-ea-ict.be:24041");
    subscriber.connect("tcp://benternet.pxl-ea-ict.be:24042");

    char push_string[] = "musicbot?>Rein van der Linden>";
    char sub_string[] = "musicbot!>Rein van der Linden>";

    //pusher.set(zmq::sockopt::subscribe,push_string);
    subscriber.set(zmq::sockopt::subscribe,sub_string);
    //subscriber.setsockopt(ZMQ_SUBSCRIBE,sub_string, strlen(sub_string));

    char temp_string[256] = "";
    char temp_string_2[256] = "";

    loop:
    char temp_string_3[265] = "musicbot?>Rein van der Linden>";

    printf("Type command...\n");
    cin >> temp_string;

    strcat(temp_string_3,temp_string);
    strcat(temp_string_3,">");
    cout << temp_string_3 << endl;

    pusher.send(zmq::buffer(temp_string_3), zmq::send_flags::none);

    printf("listening\n");
    zmq::message_t request;
    //receive a request from client
    subscriber.recv(request, zmq::recv_flags::none);
    cout << "Received " << request.to_string() << endl;


    goto loop;

    pusher.close();
    subscriber.close();
    ctx.shutdown();


    return 0;
}
