#include<iostream>
#include<map>
#include<string>

struct PlayerStats{
    std::string playerId;
    std::string playerName;
    int score;
    PlayerStats(std::string id, std::string name, int s) : playerId(id), playerName(name), score(s) {}
};

struct PlayerRankComparator{
    bool operator()(const PlayerStats &a, const PlayerStats &b) const {
        if(a.score == b.score){
            if(a.playerName == b.playerName){
                return a.playerId < b.playerId; // if score and player name are same then sort by player id
            }
            return a.playerName < b.playerName;
        }
        return a.score > b.score; // higher score should come first
    }
};


int main(){
    std::map<PlayerStats, bool, PlayerRankComparator> leaderboard;
    
    leaderboard[PlayerStats("P001", "Alice", 1500)] = true;
    leaderboard[PlayerStats("P003", "Charlie", 1200)] = true;
    leaderboard[PlayerStats("P002", "Bob", 1500)] = true;
    leaderboard[PlayerStats("P005", "David", 1800)] = true;
    leaderboard[PlayerStats("P004", "Alice", 1000)] = true;
    leaderboard[PlayerStats("P007", "Emily", 1200)] = true;
    leaderboard[PlayerStats("P006", "Bob", 1500)] = true;

    std::cout<<"Leaderboard: "<<std::endl;
    int rank = 1;
    for(const auto &entry : leaderboard){
        const PlayerStats &stats = entry.first;
        std::cout<<"Rank: ["<<rank<<"], ID: ["<<stats.playerId<<"], Name: ["<<stats.playerName<<"], Score: ["<<stats.score<<"]"<<std::endl;
        rank++;
    }

}