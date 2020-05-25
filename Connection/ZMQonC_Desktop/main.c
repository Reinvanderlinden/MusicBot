//Linux Machine/Server

#include <stdio.h>
#include <zmq.h>

#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>
#include <bits/stdc++.h>
#include <QString>


void * context;

int main( int argc, char * argv[] )
{
    printf("Started\n");
    context = zmq_ctx_new();

    void * pusher = zmq_socket( context, ZMQ_PUSH );
    void * subscriber = zmq_socket( context, ZMQ_SUB);

    zmq_connect( pusher, "tcp://benternet.pxl-ea-ict.be:24041" );
    zmq_connect( subscriber, "tcp://benternet.pxl-ea-ict.be:24042" );

    char push_string[] = "musicbot!>Rein van der Linden>";
    char sub_string[] = "musicbot?>Rein van der Linden>";

    zmq_setsockopt(pusher,ZMQ_SUBSCRIBE, push_string, strlen(push_string));
    zmq_setsockopt(subscriber,ZMQ_SUBSCRIBE, sub_string, strlen(sub_string));

    int len;
    recvn:
    printf("receiving..\n");

    char string[1000] = "";
    char backup_string[1000] = "";
    zmq_msg_t msg;
    int rc = zmq_msg_init (&msg);

   rc = zmq_recvmsg (subscriber, &msg, 0);

   int size = zmq_msg_size (&msg);
   memcpy(string, zmq_msg_data(&msg), size);
   zmq_msg_close(&msg);
   string[size] = 0;
   printf("Received string: %s\n", string);
   zmq_msg_close (&msg);

   strcpy(backup_string, string);
   //string[strlen(string)-1] = '\0';
   //char *cmd_string  = strrchr(string,'>');
   for(int i= strlen(sub_string); i <= strlen(string);i++)
   {
       string[i-strlen(sub_string)] = string[i];
   }
   printf("command: %s\n", string);

   char send_string[] = "";

   if(strstr(string,"play") != 0)
   {
    strcpy(send_string,"musicbot!>Rein van der Linden>playing>");
    //play_pauze();
   }
   else if(strstr(string,"next") != 0)
   {
    strcpy(send_string,"musicbot!>Rein van der Linden>next track...>");
    //next_track();
   }
   else if(strstr(string,"prev") != 0)
   {
    strcpy(send_string,"musicbot!>Rein van der Linden>prev track...>");
    //prev_track();
   }
   else if(strstr(string,"find") != 0)
   {
    strcpy(send_string,"musicbot!>Rein van der Linden>looking up>");
    backup_string[strlen(string)-1] = '\0';
    char *backup_string  = strrchr(string,'>');
    for(int i= 1; i <= strlen(backup_string);i++)
    {
        backup_string[i-1] = backup_string[i];
    }
    printf("command: %s\n", backup_string);
   }

   else
   {
    strcpy(send_string,"musicbot!>Rein van der Linden>i dont understand u...>");
   }
   zmq_send( pusher, send_string, strlen(send_string), 0 );
   printf("Send\n");

   goto recvn;

    zmq_close( pusher );
    zmq_close( subscriber );
    zmq_ctx_shutdown( context );
    zmq_ctx_term( context );

    return 0;
}
