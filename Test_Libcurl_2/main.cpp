#include <iostream>
#include <curl/curl.h>
#include <string>
#include <bits/stdc++.h>
//#include <QJsonArray>

int i = 1;
std::string request_string;
std::string call_token ="Authorization: Bearer ";
std::string call_token_2 ="Authorization: Basic ";
std::string refresh_token = "xxxxxxPjoGFxCSgBpzLST2h_UcitfNl-509vii8Na0MWFrvNXgmmDGZuHxaBk8OsmQ9yptya9Hh7Rg_u4ybnFLOL4M-kKMNpVbGngdZkOBXr6uaCo8ry923DOf8Y0Go8GmX_WhZWGxEgzoqb5xbnCrPfwXUBnNSdpXhWKt1_ROWncn35z5cpwNoZ77Pdgisi2dRF3q6QV_c661qgRnAZQqws67__X3IYj5IbCvf0qRmwxo21L66-7_sOK2E8saGS9d2eDJDoRDV8tQ";
//"BQAzCfPjoGFxCSgBpzLST2h_UcitfNl-509vii8Na0MWFrvNXgmmDGZuHxaBk8OsmQ9yptya9Hh7Rg_u4ybnFLOL4M-kKMNpVbGngdZkOBXr6uaCo8ry923DOf8Y0Go8GmX_WhZWGxEgzoqb5xbnCrPfwXUBnNSdpXhWKt1_ROWncn35z5cpwNoZ77Pdgisi2dRF3q6QV_c661qgRnAZQqws67__X3IYj5IbCvf0qRmwxo21L66-7_sOK2E8saGS9d2eDJDoRDV8tQ"
std::string refresh_token_2 ="MGRlYWNjNDEwYzNkNDZhZWI3MDFmYTJiZDJlZjZjOWQ6ZTk3NjIzY2I4NzM4NGQwY2EyMGFkYTA2NTA2OWY3YzE=";
char buffer[272];
struct curl_slist* headers;
char request_chararray[562];
char refresh_chararray[562];

std::string response_string;
std::string header_string;
std::size_t length;

size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}

int main(int argc, char** argv) {
    auto curl = curl_easy_init();
    if (curl) {
        run:
        switch (i) {
        case 0:
            //Request token
            request_string = "https://accounts.spotify.com/api/token";
            request_string.copy(request_chararray, request_string.size() + 1);
            request_chararray[request_string.size()] = '\0';

            call_token_2 = call_token_2 + refresh_token_2;
            call_token_2.copy(refresh_chararray, call_token_2.size() + 1);
            refresh_chararray[call_token_2.size()] = '\0';

            curl_easy_setopt(curl, CURLOPT_URL, request_chararray);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "grant_type=refresh_token&refresh_token=AQCalr4m192b3kBz-lQJPY5d4zPNDI5MJbB6FJ_ASwvsW6kCvSR9FOVC-u_JDe6ZBSdsXq0vhKNYqJ_2sLUyO_jyOAcoaljnKN6GKdRzedkTBLV6H8VLTYzbIz2JuPc6Px0");

            headers = NULL;
            //headers = curl_slist_append(headers, "Content-Type: application/json");
            headers = curl_slist_append(headers, refresh_chararray);
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
            curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);
            curl_easy_perform(curl);

            std::cout << "Response String:" << response_string << '\n';
            length = response_string.copy(buffer,272,17);
            buffer[length]='\0';
            std::cout << "buffer" << buffer << '\n';


            break;
        case 1:
            //test
            request_string = "https://api.spotify.com/v1/me/player";
            request_string.copy(request_chararray, request_string.size() + 1);
            request_chararray[request_string.size()] = '\0';

            call_token = call_token + refresh_token;
            call_token.copy(refresh_chararray, call_token.size() + 1);
            refresh_chararray[call_token.size()] = '\0';

            break;

        }
        std::size_t found = response_string.find("401");
         if (found!=std::string::npos)
            i = 0;
         else
            goto end;
        goto run;
        end:
        curl_easy_cleanup(curl);
        curl = NULL;
    }
}
