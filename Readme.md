# Spotify Controller

[![N|Solid](https://www.agconnect.nl/sites/ag/files/spotify%20logo.jpg)](https://nodesource.com/products/nsolid)

This project is a C++ bot that controls Spotify, running over a broker. The Software is made up out of A server and a client, the server will run alongside the broker making it possible to access with the client

  * [Client](https://github.com/Reinvanderlinden/MusicBot/tree/master/Client)
  * [Server](https://github.com/Reinvanderlinden/MusicBot/tree/master/Server)

# Required Parts!

  - ZMQ (cppzmq used here)
  - Spotify API (Web API used here)
  - curl (libcurl used here)
  - JSON (QJsonDocument used here)
  - File I/O (fstream used here)

### Tech

| Command | Detail |
| ------ | ------ |
| play | starts song  on spotify |
| pause | pauses song  on spotify |
| next | starts next song  on spotify |
| prev | starts previous song  on spotify |
| find | looks up a song on spotify and adds the top song as next on queue (uses the words after find as query) |
| volume | changes volume to last nurmer after volume |
| current | returns current song playing |
| devices | change device playing on (working proogress currently disabled) |

### error

if it doesnt work there are 3 pssible fixes
*first check if spotify is open somewere
*ask for 'token' to get a new refresh token
*there was another error - restart client

Made by
----

Rein van der linden
for private/school use only
