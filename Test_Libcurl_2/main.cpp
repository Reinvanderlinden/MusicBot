#include <fstream>
#include <iostream>
#include <curl/curl.h>
#include <string>
#include <bits/stdc++.h>
//#include <QJsonArray>

int i = 3;
std::string request_string;
std::string call_token ="Authorization: Bearer ";
std::string call_token_2 ="Authorization: Basic ";
std::string refresh_token;
std::string refresh_token_2 ="MGRlYWNjNDEwYzNkNDZhZWI3MDFmYTJiZDJlZjZjOWQ6ZTk3NjIzY2I4NzM4NGQwY2EyMGFkYTA2NTA2OWY3YzE=";
char buffer[272];
struct curl_slist* headers;

std::string response_string;
std::string header_string;
std::size_t length;

using namespace std;

size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}

int main() {

    auto curl = curl_easy_init();
    if (curl) {
        char request_chararray[562];
        char refresh_chararray[562];
        int volume = 50;

        char data[270];
        ofstream outfile;
        ifstream infile;

        switch (i) {
        case 0:
            //Request token
            outfile.open("token.dat");
            request_string = "https://accounts.spotify.com/api/token";
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

            length = response_string.copy(buffer,270,17);
            outfile << buffer;

            outfile.close();
            break;
        case 1:
            //info about player
            infile.open("token.dat");
            request_string = "https://api.spotify.com/v1/me/player";
            request_string.copy(request_chararray, request_string.size() + 1);
            request_chararray[request_string.size()] = '\0';

            infile >> data;
            refresh_token = data;
            //cout << refresh_token << endl;

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

            break;
        case 2:
            //Press Play
            infile.open("token.dat");
            request_string = "https://api.spotify.com/v1/me/player/play";
            request_string.copy(request_chararray, request_string.size() + 1);
            request_chararray[request_string.size()] = '\0';

            infile >> data;
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

            break;
        case 3:
            //Press pause
            infile.open("token.dat");
            request_string = "https://api.spotify.com/v1/me/player/pause";
            request_string.copy(request_chararray, request_string.size() + 1);
            request_chararray[request_string.size()] = '\0';

            infile >> data;
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

            break;
        case 4:
            //Set Volume
            infile.open("token.dat");
            request_string = "https://api.spotify.com/v1/me/player/volume?volume_percent=";
            call_token = call_token + std::to_string(volume);
            request_string.copy(request_chararray, request_string.size() + 1);
            request_chararray[request_string.size()] = '\0';

            infile >> data;
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

            break;
           case 5:
            break;

        }
        std::size_t found = response_string.find("\"status\": 40");
          if (found!=std::string::npos)
            {
                cout<<"boem"<<endl;
            }
        cout << "Response String:" << response_string << '\n';

        infile.close();
        curl_easy_cleanup(curl);
        curl = NULL;
    }
}
