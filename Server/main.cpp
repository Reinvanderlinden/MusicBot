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
QString HTTP_GET_AND_FIND(string search_term)
{
    auto curl = curl_easy_init();
    ifstream infile;
    char request_chararray[562];
    char refresh_chararray[562];
    char data[270];
    string response_string;
    string request_string;
    string header_string;
    string end_string;
    string search_string;
    string word;
    string call_token ="Authorization: Bearer ";
    struct curl_slist* headers;

    infile.open("token.dat");

    end_string = "&type=track&market=be&limit=1";
    request_string = "https://api.spotify.com/v1/search?q=";

    for (auto x : search_term)
       {
           if (x == ' ')
           {
               search_string = search_string + word+ "%20";
               word = "";
           }
           else
           {
               word = word + x;
           }
       }

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

    return 1;
}
//Function to check if token is not expired
string error_check(QString response_Qstring)
{
    bool ok;
    string error = 0;
    QString response_out;

    if (response_Qstring == NULL){
        return "0";
    }
    else
    {
    QByteArray json_bytes = response_Qstring.toLocal8Bit();
    auto json_doc=QJsonDocument::fromJson(json_bytes);

    QJsonObject json_obj=json_doc.object();
    QJsonObject root_obj = json_doc.object();
    QVariantMap root_map = root_obj.toVariantMap();
    QVariantMap tracks_map = root_map["error"].toMap();

    QJsonObject items_obj = tracks_map["error"].toJsonObject();
    QVariantMap items_map = items_obj.toVariantMap();

    response_out = tracks_map["status"].toString();
    cout << response_out.toStdString() << endl;

    if (response_out.toStdString() == "401" ||response_out.toStdString() == "404")
     {
        ok = HTTP_REFRESH_TOKEN_PUT();
     }
        return response_out.toStdString();
    }

}

int main() {

    QString response_Qstring;
            bool ok = 1;

            string tmp_string;
            int volume = 50;
            loop:
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
               char editable_string[1000] = "";

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
                response_Qstring = HTTP_PUT("https://api.spotify.com/v1/me/player/play");
                strcpy(send_string,"musicbot!>Rein van der Linden>playing>");

               }
               else if(strstr(cmd_string,"pause") != 0)
               {
                strcpy(send_string,"musicbot!>Rein van der Linden>pause...>");
                response_Qstring = HTTP_PUT("https://api.spotify.com/v1/me/player/pause");
               }
               else if(strstr(cmd_string,"next") != 0)
               {
                strcpy(send_string,"musicbot!>Rein van der Linden>next track...>");
                response_Qstring = HTTP_POST("https://api.spotify.com/v1/me/player/next");
               }
               else if(strstr(cmd_string,"prev") != 0)
               {
                strcpy(send_string,"musicbot!>Rein van der Linden>prev track...>");
                response_Qstring = HTTP_POST("https://api.spotify.com/v1/me/player/previous");
               }
               else if(strstr(cmd_string,"volume") != 0)
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
                  if(temp_int > 100 || temp_int < 0)
                  {
                  strcpy(send_string, "musicbot!>Rein van der Linden>change to fail volume out of range!>");
                  }
                  else
                  {
                  std::string begin_str = "musicbot!>Rein van der Linden>changed volume to ";
                  std::string end_str =">";
                  begin_str = begin_str + std::to_string(temp_int) + end_str;
                  char mid_string[1000];
                  begin_str.copy(mid_string, begin_str.size() + 1);
                  mid_string[begin_str.size()] = '\0';
                  strcpy(send_string, mid_string);
                  tmp_string = "https://api.spotify.com/v1/me/player/volume?volume_percent=";
                  tmp_string = tmp_string + std::to_string(volume);
                  response_Qstring = HTTP_PUT(tmp_string);
                  }
               }
               else if(strstr(cmd_string,"find") != 0)
               {
                strcpy(send_string,"musicbot!>Rein van der Linden>looking up>");

                strcpy(editable_string,cmd_string);

                for(int i = 3;i < strlen(editable_string);i++)
                {
                    editable_string[i-5] = editable_string[i];
                }
                for(int i = (strlen(editable_string) - 4);i < strlen(editable_string);i++)
                {
                    editable_string[i] = ' ';
                }
                editable_string[(strlen(editable_string) - 4)] = '\0';
                 response_Qstring = HTTP_GET_AND_FIND(editable_string);
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

                 response_Qstring = items_map["id"].toString();
                 std::string url = "https://api.spotify.com/v1/me/player/queue?uri=spotify:track:";
                 char uri[1000];
                 url = url + response_Qstring.toStdString();
                 url.copy(uri, url.size() + 1);
                 uri[url.size()] = '\0';
                 response_Qstring = HTTP_POST(uri);


               }
               else if(strstr(cmd_string,"token") != 0)
               {
                  strcpy(send_string,"musicbot!>Rein van der Linden>fetching token>");
                  ok = HTTP_REFRESH_TOKEN_PUT();
               }
               else if(strstr(cmd_string,"current") != 0)
               {
                  response_Qstring = HTTP_GET("https://api.spotify.com/v1/me/player/currently-playing");
                  QByteArray json_bytes = response_Qstring.toLocal8Bit();
                  auto json_doc=QJsonDocument::fromJson(json_bytes);

                  QJsonObject json_obj=json_doc.object();
                  QJsonObject root_obj = json_doc.object();
                  QVariantMap root_map = root_obj.toVariantMap();
                  QVariantMap tracks_map = root_map["item"].toMap();

                  QJsonObject items_obj = tracks_map["item"].toJsonObject();
                  QVariantMap items_map = items_obj.toVariantMap();

                  QString song_name = tracks_map["name"].toString();
                  std::string song_name_str = song_name.toStdString();
                  char song_arr[1000];
                  std::string begin_str_resp = "musicbot!>Rein van der Linden>u are currently listening to ";
                  begin_str_resp = begin_str_resp + song_name_str + ">";
                  begin_str_resp.copy(song_arr, begin_str_resp.size() + 1);
                  song_arr[begin_str_resp.size()] = '\0';
                  strcpy(send_string,song_arr);

               }
//               else if(strstr(cmd_string,"device") != 0)
//               {
//                  response_Qstring = HTTP_GET("https://api.spotify.com/v1/me/player/devices");

//                  QByteArray json_bytes = response_Qstring.toLocal8Bit();
//                  auto json_doc=QJsonDocument::fromJson(json_bytes);

//                  QJsonObject json_obj = json_doc.object();
//                  QJsonObject root_obj = json_doc.object();
//                  QVariantMap root_map = root_obj.toVariantMap();
//                  QJsonArray  items_arr = root_map["devices"].toJsonArray();

//                  QJsonValue  items_val = items_arr.at(0);
//                  QJsonObject items_obj = items_val.toObject();
//                  QVariantMap items_map = items_obj.toVariantMap();

//                   QString ID;
//                  if (items_map["is_active"].toString()=="false")
//                  {

//                      ID = items_map["id"].toString();
//                  }

//                  cout << response_Qstring.toStdString() << endl;

//                  std::string ID_str = ID.toStdString();
//                  cout << ID.toStdString() << endl;
//                  char ID_arr[1000];
//                  std::string begin_str_resp = "https://api.spotify.com/v1/me/player/pause?device_id=";
//                  begin_str_resp = begin_str_resp + ID_str;
//                  begin_str_resp.copy(ID_arr, begin_str_resp.size() + 1);
//                  ID_arr[begin_str_resp.size()] = '\0';
//                  response_Qstring = HTTP_PUT(ID_arr);
//                  cout << response_Qstring.toStdString() << endl;

//                  strcpy(send_string,"musicbot!>Rein van der Linden>u switched devices i hope...>");

//               }
               else
               {
                strcpy(send_string,"musicbot!>Rein van der Linden>i dont understand u...>");
               }



              size_t t = (strlen(send_string)+1);
              zmq::message_t send;
              send = zmq::message_t(send_string, t);
              pusher.send(send, zmq::send_flags::none);


            cout << "Response String:" << response_Qstring.toStdString() << '\n';



            pusher.close();
            subscriber.close();
            ctx.shutdown();
            goto loop;



            return 0;
    }
