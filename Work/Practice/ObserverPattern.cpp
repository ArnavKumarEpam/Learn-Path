#include<bits/stdc++.h>
using namespace std;

class ISubscriber{
    public:
        virtual void update() = 0;
};
class IChannel{
    public:
        virtual void subscribe(ISubscriber* subscriber) = 0;
        virtual void unsubscribe(ISubscriber* subscriber) = 0;
        virtual void notify() = 0;
};
class Channel : public IChannel{
    private:
        string latestVideo;
        vector<ISubscriber*> subscribers;
    public:
        void subscribe(ISubscriber * subscriber){
            if(find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end()){
                subscribers.push_back(subscriber);
            }
            else {
                cout<<"Already subscribed"<<endl;
            }
        }
        void unsubscribe(ISubscriber * subscriber){
            if(find(subscribers.begin(), subscribers.end(), subscriber) != subscribers.end()){
                subscribers.erase(remove(subscribers.begin(), subscribers.end(), subscriber), subscribers.end());
            }
            else {
                cout<<"Not subscribed"<<endl;
            }
        }
        void upLoadVideo(string video){
            latestVideo = video;
            notify();
        }
        void getVideo(){
            cout<<"Latest video: "<<latestVideo<<endl;
        }
        void notify(){
            for(auto subscriber : subscribers){
                subscriber->update();
            }
        }
};

class Subscriber : public ISubscriber{
    private:
        string name;
        Channel * channel;
    public:
        Subscriber(string name, Channel * channel){
            this -> name = name;
            this -> channel = channel;
        }
        void update(){
            cout<<"Hey "<<name <<"! New video uploaded, check it out!"<<endl;
            channel->getVideo();
        }
};

int main(){
    Channel * channel = new Channel();
    ISubscriber * sub1 = new Subscriber("A", channel);
    ISubscriber * sub2 = new Subscriber("B", channel);
    channel->subscribe(sub1);
    channel->subscribe(sub2);
    channel->upLoadVideo("Observer Pattern in C++");
    channel->unsubscribe(sub1);
    channel->upLoadVideo("Observer Pattern in C++ - Part 2");
}