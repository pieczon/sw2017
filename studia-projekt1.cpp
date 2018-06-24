#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <curses.h>

int main()
{
    std::ofstream xmlFile;
    std::ifstream xmlFile1;
    
    std::string name="",pass="";
    std::string ntyp="Wi-Fi",netType,fileTest=">test.txt",check,ntype,fil,xfileName,fileName="myWlan.xml";
    char c='"',cho='2',cho1='1',c1;
    netType=c+ntyp+c+fileTest;
    xfileName=c+fileName+c;
    int succ=0;

        system("netsh wlan show networks");
        std::cout<<"TO REFRESH PRESS : 1\n\nTO CHOOSE NETWORK PRESS : 2\n\n   >   ";
        cho=getch();

    if (cho!='2')
    {
        std::cout<<"\n    Enter the desired network name-------:       ";
        std::cin>>name;
    do
    {
        std::cout<<"\n    Enter wifi Password------:        ";
        std::cin>>pass;
        xmlFile.open(fileName.c_str());

        //Writing a xml file .....................

        xmlFile<<"<?xml version="<<c<<"1.0"<<c<<"?>\n";
        xmlFile<<"<WLANProfile xmlns="<<c<<"http://www.microsoft.com/networking/WLAN/profile/v1"<<c<<">\n";
        xmlFile<<"<name>";
        xmlFile<<name;
        xmlFile<<"</name>\n<SSIDConfig>\n<SSID>\n<hex>";
        for(int i=0;i<name.length();i++)
        xmlFile << std::hex << (int)name.at(i);
        xmlFile<<"</hex>\n<name>";
        xmlFile<<name;
        xmlFile<<"</name>\n</SSID>\n</SSIDConfig>\n<connectionType>ESS</connectionType>\n<connectionMode>auto</connectionMode>\n<MSM>\n<security>\n<authEncryption>";
        xmlFile<<"\n<authentication>WPA2PSK</authentication>\n<encryption>AES</encryption>\n<useOneX>false</useOneX>\n</authEncryption>\n<sharedKey>";
        xmlFile<<"\n<keyType>passPhrase</keyType>\n<protected>false</protected>\n<keyMaterial>";
        xmlFile<<pass;
        xmlFile<<"</keyMaterial>\n</sharedKey>\n</security>\n</MSM>\n";
        xmlFile<<"<MacRandomization xmlns="<<c<<"http://www.microsoft.com/networking/WLAN/profile/v3"<<c<<">\n";
        xmlFile<<"<enableRandomization>false</enableRandomization>\n</MacRandomization>\n</WLANProfile>";
        xmlFile.close();

        //addd the xml file to system profile.............
        system(("netsh wlan add profile filename="+xfileName).c_str());
        //to let system realize what changes have been made...............
        system("timeout");
        //to check if connected...........
        system(("netsh interface show interface name="+netType).c_str());

        xmlFile1.open("test.txt");
        while(!xmlFile1.eof())
        {
            xmlFile1>>c1;
            if(c1==':')
            {
                for(int i=0;i<9;i++)
                {
                    xmlFile1>>c1;
                    check=check+c1;
                }
            }
                if(check=="Connected")
                {
                    std::cout<<"...............................................You are connected!!.................................";
                    succ=1;break;
                }
                if(check!="Connected")check="";
        }
        xmlFile1.close();
        if(succ==1)break;
    }while(succ!=1);

    }

    return 0;
}