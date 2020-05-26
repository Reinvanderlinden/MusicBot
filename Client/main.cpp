//Laptop
#include <stdio.h>
#include <string>
#include <zmq.hpp>
#include <iostream>

using namespace std;

void * context; //Global context, because you only need one !

int main( int argc, char * argv[] )
{
    zmq::context_t ctx;

    zmq::socket_t pusher(ctx, zmq::socket_type::push);
    zmq::socket_t subscriber(ctx, zmq::socket_type::sub);

    pusher.connect("tcp://benternet.pxl-ea-ict.be:24041");
    subscriber.connect("tcp://benternet.pxl-ea-ict.be:24042");

    char sub_string[] = "musicbot!>Rein van der Linden>";

    //pusher.set(zmq::sockopt::subscribe,push_string);
    subscriber.set(zmq::sockopt::subscribe,sub_string);
    //subscriber.setsockopt(ZMQ_SUBSCRIBE,sub_string, strlen(sub_string));



    loop:
    std::string temp_string = "";
    char temp_char[100];
    char temp_string_3[] = "musicbot?>Rein van der Linden>";

    printf("Type command...\n");
    std::getline (std::cin,temp_string);
    temp_string.copy(temp_char, temp_string.size() + 1);
    temp_char[temp_string.size()] = '\0';

    strcat(temp_string_3,temp_char);
    strcat(temp_string_3,">");
    //cout << temp_string_3 << endl;

    size_t t = (strlen(temp_string_3)+1);
    zmq::message_t send;
    send = zmq::message_t(temp_string_3, t);
    pusher.send(send, zmq::send_flags::none);

    printf("Response...\n");

    zmq::message_t request;
    subscriber.recv(request, zmq::recv_flags::none);

    string out_string = request.to_string();

    char out_char[1000] = " ";
    out_string.copy(out_char, out_string.size() + 1);
    out_char[out_string.size()] = '\0';

    out_char[strlen(out_char)-1] = '\0';
   char *out_char_2  = strrchr(out_char,'>');
   for(size_t i= 1; i <= strlen(out_char_2);i++)
   {
       out_char_2[i-1] = out_char_2[i];
   }

    cout << out_char_2 << endl;


    goto loop;

    pusher.close();
    subscriber.close();
    ctx.shutdown();


    return 0;
}
