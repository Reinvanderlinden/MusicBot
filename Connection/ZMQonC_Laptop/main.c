//Laptop
#include <stdio.h>
#include <string.h>
#include <zmq.h>

void * context; //Global context, because you only need one !

int main( int argc, char * argv[] )
{
    printf("Started\n");
    context = zmq_ctx_new();

    void * pusher = zmq_socket( context, ZMQ_PUSH );
    void * subscriber = zmq_socket( context, ZMQ_SUB);

    zmq_connect( pusher, "tcp://benternet.pxl-ea-ict.be:24041" );
    zmq_connect( subscriber, "tcp://benternet.pxl-ea-ict.be:24042" );

    char push_string[] = "musicbot?>Rein van der Linden>";
    char sub_string[] = "musicbot!>Rein van der Linden>";

    zmq_setsockopt(pusher,ZMQ_SUBSCRIBE, push_string, strlen(push_string));
    zmq_setsockopt(subscriber,ZMQ_SUBSCRIBE, sub_string, strlen(sub_string));

    char temp_string_2[] = "musicbot?>Rein van der Linden>play>";

    zmq_send( pusher, temp_string_2, strlen(temp_string_2), 0 );

    char string[1000] = "";
    zmq_msg_t msg;
    int rc = zmq_msg_init (&msg);
    rc = zmq_recvmsg (subscriber, &msg, 0);

   int size = zmq_msg_size (&msg);
   memcpy(string, zmq_msg_data(&msg), size);
   zmq_msg_close(&msg);
   string[size] = 0;
   printf("%s\n", string);
    zmq_msg_close (&msg);


    zmq_close( pusher );
    zmq_close( subscriber );
    zmq_ctx_shutdown( context );
    zmq_ctx_term( context );

    return 0;
}
