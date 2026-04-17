#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
 struct Student {
     int id;
     std::string name;
     bool active;
     double grade;
     
     Student(int i, std::string n, bool a, double g) 
         : id(i), name(n), active(a), grade(g) {}
 };

struct StudentRoster{
        std::list<Student> studentsList;
        std::vector<Student> studentsVector;
        std::map<int, Student> studentsMap;
    public:
        void removeFailedStudentsVector(){
            // Original Bug: Used range-based for loop with erase(), causing
            // iterator invalidation. Range-based loops don't handle iterator
            // updates from erase() operations.
            // 
            // Fix: Explicit iterator loop where erase() returns the next
            // valid iterator, preventing invalidation issues.
            // Erase-remove idiom: More efficient for vectors as it minimizes
            // element shifting by doing removal in two phases
            studentsVector.erase(std::remove_if(studentsVector.begin(),
                    studentsVector.end(), [](const Student &s){
                        return s.grade < 60.0;
            }), studentsVector.end());
        
            
        }
        void removeInactiveStudentsList(){
            for(auto it = studentsList.begin(); it != studentsList.end() ;){
                if(!it -> active){
                    it = studentsList.erase(it);
                }
                else ++it;
            }
            
        }

        void removeLowGradesMap(double threshold){
            for(auto it = studentsMap.begin() ; it != studentsMap.end() ;){
                if(it -> second.grade < threshold){
                    it = studentsMap.erase(it);
                }
                else ++it;
            }
        } 
        

        void cleanupVector() {
            for(auto it = studentsVector.begin() ; it != studentsVector.end() ;){
                if(it -> grade < 60.0 || !it -> active){
                    it = studentsVector.erase(it);
                }
                else ++it;
            }
        }
        
        
        
        void addStudent(int id, std::string name, bool active, double grade) {
         Student s(id, name, active, grade);
         studentsVector.push_back(s);
         studentsList.push_back(s);
         studentsMap.emplace(id, s);
     }
     
     // Print all students
     void printRoster() {
         std::cout << "Vector (" << studentsVector.size() << "): ";
         for (const auto& s : studentsVector) 
             std::cout << s.name << "(" << s.grade << ") ";
         
         std::cout << "\nList (" << studentsList.size() << "): ";
         for (const auto& s : studentsList) 
             std::cout << s.name << "(" << s.grade << ") ";
         
         std::cout << "\nMap (" << studentsMap.size() << "): ";
         for (const auto& [id, s] : studentsMap) 
             std::cout << s.name << "(" << s.grade << ") ";
         
         std::cout << "\n---\n";
     }
 };

 
 int main() {
     StudentRoster roster;
     
     // Test data
     roster.addStudent(1, "Alice", true, 95.5);
     roster.addStudent(2, "Bob", false, 45.0);     // Inactive, failing
     roster.addStudent(3, "Charlie", true, 58.5);   // Failing
     roster.addStudent(4, "Diana", true, 88.0);
     roster.addStudent(5, "Eve", false, 30.0);      // Inactive, failing
     
     std::cout << "Initial roster:\n";
     roster.printRoster();
     
     // These calls have iterator invalidation bugs!
     // Your task: Refactor these methods
     roster.removeFailedStudentsVector();   // Remove grade < 60
     roster.removeInactiveStudentsList();   // Remove inactive
     roster.removeLowGradesMap(50.0);       // Remove grade < 50
     roster.cleanupVector();                // Complex cleanup
     
     std::cout << "After removals (should be bug-free):\n";
     roster.printRoster();
     
     return 0;
 }