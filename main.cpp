#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <curl/curl.h>

using namespace std;

int main()
{
    CURL* curl = curl_easy_init();
    CURLcode res;
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.spotify.com/v1/me/player");
    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "Authorization: Bearer BQDtQefHUFBeZaCRng7-v5tzP2jxDYKvaoDhuVLF5kiKGoDM_UfyMaMhAKtLegwv6MfekYX6DLuk8hGKDW3FQtQrkEVFuPcM0039my7G1xo--4SOqFclBGEnn5OCJR9bXDKZgvC9rX_KWQb47YvJzlV3ddY6r1ZtS6Mkrl0ZxSEioTm-YqNx98hg8VaLNk0kWyDn9nqP3kQd58ECxz_ENyq0TULJzzLLZsO-ucsrsEJ-m_RSNH0XTF1v2OUBh_Q4LyTjmhM_6TXyXg");

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
        cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
    }

    curl_easy_cleanup(curl);

    return 0;
}
