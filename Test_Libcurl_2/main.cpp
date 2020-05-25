#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include <string>
#include <bits/stdc++.h>
#include <QString>

#include <zmq.hpp>

#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QVariant>
#include <QJsonArray>
#include <QDebug>

#include<sstream> //For Extracting numbers

using namespace std;
void * context;

//Function to get curl output
size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data)
{
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}
//Function to perform HTTP Get AND FIND
QString HTTP_GET_AND_FIND(string request_string, string search_term)
{
    auto curl = curl_easy_init();
    ifstream infile;
    char request_chararray[562];
    char refresh_chararray[562];
    char data[270];
    string response_string;
    string header_string;
    string end_string;
    string search_string;
    string call_token ="Authorization: Bearer ";
    struct curl_slist* headers;

    infile.open("token.dat");

    end_string = "&type=track&market=be&limit=1";
    request_string = "https://api.spotify.com/v1/search?q=";



    request_string = request_string + search_string + end_string;

    request_string.copy(request_chararray, request_string.size() + 1);
    request_chararray[request_string.size()] = '\0';
    request_string.copy(request_chararray, request_string.size() + 1);
    request_chararray[request_string.size()] = '\0';

    infile >> data;
    string refresh_token = "";
    refresh_token = data;


    call_token = call_token + refresh_token;
    call_token.copy(refresh_chararray, call_token.size() + 1);
    refresh_chararray[call_token.size()] = '\0';

    curl_easy_setopt(curl, CURLOPT_URL, request_chararray);

    headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, refresh_chararray);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
    curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);

    curl_easy_perform(curl);

    infile.close();
    curl_easy_cleanup(curl);
    curl = NULL;

    return QString::fromStdString(response_string);

}
//Function to perform HTTP Get
QString HTTP_GET(string request_string)
{
    auto curl = curl_easy_init();
    ifstream infile;
    char request_chararray[562];
    char refresh_chararray[562];
    char data[270];
    string response_string;
    string header_string;
    string call_token ="Authorization: Bearer ";
    struct curl_slist* headers;

    infile.open("token.dat");
    request_string.copy(request_chararray, request_string.size() + 1);
    request_chararray[request_string.size()] = '\0';

    infile >> data;
    string refresh_token = "";
    refresh_token = data;


    call_token = call_token + refresh_token;
    call_token.copy(refresh_chararray, call_token.size() + 1);
    refresh_chararray[call_token.size()] = '\0';

    curl_easy_setopt(curl, CURLOPT_URL, request_chararray);

    headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, refresh_chararray);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
    curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);

    curl_easy_perform(curl);

    infile.close();
    curl_easy_cleanup(curl);
    curl = NULL;

    return QString::fromStdString(response_string);

}
//Function to prerform HTTP post
QString HTTP_POST(string request_string)
{
    auto curl = curl_easy_init();
    ifstream infile;
    char request_chararray[562];
    char refresh_chararray[562];
    char data[270];
    string response_string;
    string header_string;
    string call_token ="Authorization: Bearer ";
    struct curl_slist* headers;

    infile.open("token.dat");
    request_string.copy(request_chararray, request_string.size() + 1);
    request_chararray[request_string.size()] = '\0';

    infile >> data;
    string refresh_token = "";
    refresh_token = data;


    call_token = call_token + refresh_token;
    call_token.copy(refresh_chararray, call_token.size() + 1);
    refresh_chararray[call_token.size()] = '\0';

    curl_easy_setopt(curl, CURLOPT_URL, request_chararray);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");

    headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, refresh_chararray);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
    curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);

    curl_easy_perform(curl);

    infile.close();
    curl_easy_cleanup(curl);
    curl = NULL;

    return QString::fromStdString(response_string);

}
//Function to perform HTTP PUT/Upload
QString HTTP_PUT(string request_string)
{
    auto curl = curl_easy_init();
    ifstream infile;
    char request_chararray[562];
    char refresh_chararray[562];
    char data[270];
    string response_string;
    string header_string;
    string call_token ="Authorization: Bearer ";
    struct curl_slist* headers;

    infile.open("token.dat");
    request_string.copy(request_chararray, request_string.size() + 1);
    request_chararray[request_string.size()] = '\0';

    infile >> data;
    string refresh_token = "";
    refresh_token = data;

    call_token = call_token + refresh_token;
    call_token.copy(refresh_chararray, call_token.size() + 1);
    refresh_chararray[call_token.size()] = '\0';

    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
    curl_easy_setopt(curl, CURLOPT_PUT, 1L);
    curl_easy_setopt(curl, CURLOPT_URL, request_chararray);
    curl_easy_setopt(curl, CURLOPT_READDATA, "");
    curl_easy_setopt(curl, CURLOPT_INFILESIZE_LARGE,0);

    headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, refresh_chararray);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
    curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);

    curl_easy_perform(curl);

    infile.close();
    curl_easy_cleanup(curl);
    curl = NULL;
    return QString::fromStdString(response_string);
}
//Function to request refresh token (once every 3600 sec needed)
bool HTTP_REFRESH_TOKEN_PUT()
{
    auto curl = curl_easy_init();
    ofstream outfile;
    char request_chararray[562];
    char refresh_chararray[562];
    bool result;
    string response_string;
    string header_string;
    string call_token_2 ="Authorization: Basic ";
    string refresh_token_2 ="MGRlYWNjNDEwYzNkNDZhZWI3MDFmYTJiZDJlZjZjOWQ6ZTk3NjIzY2I4NzM4NGQwY2EyMGFkYTA2NTA2OWY3YzE=";
    char buffer[270];
    struct curl_slist* headers;

    //Request token
    outfile.open("token.dat");
    string request_string = "https://accounts.spotify.com/api/token";
    request_string.copy(request_chararray, request_string.size() + 1);
    request_chararray[request_string.size()] = '\0';

    call_token_2 = call_token_2 + refresh_token_2;
    call_token_2.copy(refresh_chararray, call_token_2.size() + 1);
    refresh_chararray[call_token_2.size()] = '\0';

    curl_easy_setopt(curl, CURLOPT_URL, request_chararray);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "grant_type=refresh_token&refresh_token=AQCalr4m192b3kBz-lQJPY5d4zPNDI5MJbB6FJ_ASwvsW6kCvSR9FOVC-u_JDe6ZBSdsXq0vhKNYqJ_2sLUyO_jyOAcoaljnKN6GKdRzedkTBLV6H8VLTYzbIz2JuPc6Px0");

    headers = NULL;
    headers = curl_slist_append(headers, refresh_chararray);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
    curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);
    curl_easy_perform(curl);

    response_string.copy(buffer,270,17);
    outfile << buffer;

    outfile.close();
    curl_easy_cleanup(curl);
    curl = NULL;
    if(/*status 404*/true)
       result = 1;
    else
       result = 0;

    return result;
}

int main() {
        QString response_Qstring;
        bool ok = 1;

        string tmp_string;
        string search_string = "Mijn%20Stad";
        int volume = 50;
        loop:
        printf("Started\n");
           zmq::context_t ctx;

           zmq::socket_t pusher(ctx, zmq::socket_type::push);
           zmq::socket_t subscriber(ctx, zmq::socket_type::sub);

           pusher.connect("tcp://benternet.pxl-ea-ict.be:24041");
           subscriber.connect("tcp://benternet.pxl-ea-ict.be:24042");

           //char push_string[] = "musicbot!>Rein van der Linden>";
           char sub_string[] = "musicbot?>Rein van der Linden>";

           //pusher.set(zmq::sockopt::subscribe,push_string);
           subscriber.set(zmq::sockopt::subscribe,sub_string);

           //char temp_string[256] = "";
           char string[1000] = "";

           //ok = HTTP_REFRESH_TOKEN_PUT();


           printf("listening to requests...\n");
           zmq::message_t request;
           //receive a request from client
           subscriber.recv(request, zmq::recv_flags::none);

           std::string rcv_string = "";
           rcv_string = request.to_string();
           rcv_string.copy(string, rcv_string.size() + 1);
           string[rcv_string.size()] = '\0';

           string[strlen(string)-1] = '\0';
           char *cmd_string  = strrchr(string,'>');
           for(int i= 1; i <= strlen(cmd_string);i++)
           {
               cmd_string[i-1] = cmd_string[i];
           }
           cout << cmd_string << endl;
           char send_string[] = "";

           if(strstr(cmd_string,"play") != 0)
           {
            strcpy(send_string,"musicbot!>Rein van der Linden>playing>");
            response_Qstring = HTTP_PUT("https://api.spotify.com/v1/me/player/play");
           }
           else if(strstr(string,"pause") != 0)
           {
            strcpy(send_string,"musicbot!>Rein van der Linden>pause...>");
            response_Qstring = HTTP_PUT("https://api.spotify.com/v1/me/player/pause");
           }
           else if(strstr(string,"next") != 0)
           {
            strcpy(send_string,"musicbot!>Rein van der Linden>next track...>");
            response_Qstring = HTTP_POST("https://api.spotify.com/v1/me/player/next");
           }
           else if(strstr(string,"prev") != 0)
           {
            strcpy(send_string,"musicbot!>Rein van der Linden>prev track...>");
            response_Qstring = HTTP_POST("https://api.spotify.com/v1/me/player/previous");
           }
           else if(strstr(string,"volume") != 0)
           {
              stringstream str_strm;
              str_strm << cmd_string;
              std::string temp_str;
              int temp_int;
              while(!str_strm.eof()) {
                     str_strm >> temp_str;
                     if(stringstream(temp_str) >> temp_int) {
                        volume = temp_int;
                     }
                     temp_str = "";
                  }


            strcpy(send_string,"musicbot!>Rein van der Linden>changed volume to>");
            tmp_string = "https://api.spotify.com/v1/me/player/volume?volume_percent=";
            tmp_string = tmp_string + std::to_string(volume);
            response_Qstring = HTTP_PUT(tmp_string);
           }
           else if(strstr(string,"find") != 0)
           {
            strcpy(send_string,"musicbot!>Rein van der Linden>looking up>");

            stringstream str_strm;
            str_strm << cmd_string;
            std::string temp_str;
            int temp_int;
            while(!str_strm.eof()) {
                   str_strm >> temp_str;
                   if(stringstream(temp_str) >> temp_int) {
                      volume = temp_int;
                   }
                   temp_str = "";
                }

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




          size_t t = (strlen(send_string)+1);
          zmq::message_t send;
          send = zmq::message_t(send_string, t);
          pusher.send(send, zmq::send_flags::none);


        switch (8) {
        case 4:
            tmp_string = "https://api.spotify.com/v1/me/player/volume?volume_percent=";
            tmp_string = tmp_string + std::to_string(volume);
            response_Qstring = HTTP_PUT(tmp_string);
            break;
        case 5:
            response_Qstring = HTTP_PUT("https://api.spotify.com/v1/me/player/next");
            break;
        case 6:
            response_Qstring = HTTP_PUT("https://api.spotify.com/v1/me/player/previous");
            break;
        case 7: //Search
//                std::string end_string;

//                infile.open("token.dat");
//                end_string = "&type=track&market=be&limit=1";
//                request_string = "https://api.spotify.com/v1/search?q=";

//                request_string = request_string + search_string + end_string;

//                request_string.copy(request_chararray, request_string.size() + 1);
//                request_chararray[request_string.size()] = '\0';

//                infile >> data;
//                refresh_token = data;

//                call_token = call_token + refresh_token;
//                call_token.copy(refresh_chararray, call_token.size() + 1);
//                refresh_chararray[call_token.size()] = '\0';

//                curl_easy_setopt(curl, CURLOPT_URL, request_chararray);

//                headers = NULL;
//                headers = curl_slist_append(headers, "Content-Type: application/json");
//                headers = curl_slist_append(headers, refresh_chararray);
//                curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

//                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
//                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
//                curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);

//                curl_easy_perform(curl);

             break;
            case 8:
             break;

        }

        cout << "Response String:" << response_Qstring.toStdString() << '\n';



        pusher.close();
        subscriber.close();
        ctx.shutdown();
        goto loop;


        cout << "Response String:" << response_Qstring.toStdString() << "bool:" << ok << '\n';

        QByteArray json_bytes = response_Qstring.toLocal8Bit();
        auto json_doc=QJsonDocument::fromJson(json_bytes);

        QJsonObject json_obj=json_doc.object();
        QJsonObject root_obj = json_doc.object();
        QVariantMap root_map = root_obj.toVariantMap();
        QVariantMap tracks_map = root_map["tracks"].toMap();

        QJsonArray  items_arr = tracks_map["items"].toJsonArray();
        QJsonValue  items_val = items_arr.at(0);
        QJsonObject items_obj = items_val.toObject();
        QVariantMap items_map = items_obj.toVariantMap();

        qDebug() << "ID : " << items_map["id"].toString();

        return 0;

    }
