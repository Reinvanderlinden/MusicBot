
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

    zmq_setsockopt(pusher,ZMQ_SUBSCRIBE,"musicbot?>Rein van der Linden>", 29);
    zmq_setsockopt(subscriber,ZMQ_SUBSCRIBE,"musicbot!>Rein van der Linden>", 29);
    //zmq_setsockopt(pusher,ZMQ_SUBSCRIBE,"example>answer?>Rein van der Linden>", 36);
    //zmq_setsockopt(subscriber,ZMQ_SUBSCRIBE,"example>answer!>Rein van der Linden>", 36);

    zmq_send( pusher, "musicbot?>Rein van der Linden>", 34, 0 );
    printf("Send\n");

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


//    zmq_send( pusher, "example>answer?>Rein van der Linden>CORONA-FREE-CHANNEL>0ca399dd82974b284b2edb0e0acfbc1900ca00bc>*HATSJU*>", 107, 0 );
//    zmq_msg_t msg2;
//    int rc2 = zmq_msg_init (&msg2);
//    rc = zmq_recvmsg (subscriber, &msg2, 0);
//    int size2 = zmq_msg_size (&msg2);
//       memcpy(string, zmq_msg_data(&msg2), size);
//       zmq_msg_close(&msg2);
//       string[size2] = 0;
//       printf("%s\n", string);
//    zmq_msg_close (&msg2);


    zmq_close( pusher );
    zmq_close( subscriber );
    zmq_ctx_shutdown( context );
    zmq_ctx_term( context );

    return 0;
}
