#include<iostream>

class Playable{
    public:
        virtual void play() = 0;
        virtual void pause() = 0;
};

class Recordable{
    public:
        virtual void record() = 0;
        virtual void stop() = 0;
};

class MediaPlayer : public Playable, public Recordable{
    public:
        void play(){
            std::cout<<"Playing the media! \n";
        }
        void pause(){
            std::cout<<"Paused the media! \n";
        }
        void record(){
            std::cout<<"Recording the media! \n";
        }
        void stop(){
            std::cout<<"Stopped the media! \n";
        }
};


int main(){
    MediaPlayer mp;
    Playable * p = &mp;
    p->play();
    p->pause();
    Recordable * r = &mp;
    r->record();
    r->stop();
    
}
