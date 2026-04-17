    #include<iostream>
    #include<list>
    #include<algorithm>

    const int CACHE_CAPACITY = 6;

    void accessCache(std::list<int> &cache, int value){
        if(std::find(cache.begin(), cache.end(), value) != cache.end()){
            std::cout<<"Value existed in the cache! moving it to the front. "<<std::endl;
            auto it = cache.begin();
            while(it != cache.end()){
                if(*it == value){
                    it = cache.erase(it);
                }
                else ++it;
            }
            cache.push_front(value);
        }
        else{
            cache.push_front(value);
            std::cout<<"Value added to the front of the cache! "<<std::endl;
            if(cache.size() > CACHE_CAPACITY){ // the most least recently used value is at the back of the cache as we are adding new elements at the front of the cache and moving existing to the front as well so the most least recently used value goes to the back of the cache
                int lru_value = cache.back();
                cache.pop_back();
                std::cout<<"Cache exceeded capacity! Removing least recently used value ("<<lru_value<<") from the back. "<<std::endl;
            }
        }
    }

    void display(const std::list<int> &cache){ // displaying the cache
        for(const auto &value : cache){
            std::cout<<value<<" ";
        }
        std::cout<<std::endl;
    }

    int main(){
        std::list<int> cache;

        for(int i = 0 ; ; i++){ // infinite loop to keep accepting values until user decides to exit by entering -1
            std::cout<<"Enter values in the cache: (-1 to exit)"<<std::endl;
            int value;
            if(!(std::cin >> value)){
                std::cerr<<"Invalid input! "<<std::endl;
                return 1;
            }
            if(value == -1){
                break;
            }
            accessCache(cache, value);
            std::cout<<"Current cache state: "<<std::endl;
            display(cache);
        }

        std::cout<<"Final state of the cache: "<<std::endl;
        display(cache);


    }