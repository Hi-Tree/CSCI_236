#include "Maze.hpp"
#include <iostream>
#include "Solutions.cpp"

using namespace std;

int main(){
Maze maze("Maze Data/maze_1.csv");
std::vector<MazeNode> cat = solutions::solveDEF(maze);
for(int i = 0; i < cat.size(); i++ ){
  cout << cat[i] << endl;
}
}

  /* for(int i = Final.size()-1; i > 0 ; i--){
            std::pair<int, int> point = Final[(i)].getPos();
            std::pair<int, int> point2 = Final[(i-1)].getPos();
            int x = std::abs(point.first - point2.first);
            int y = std::abs(point.second - point2.second);
           
       if(x+y != 1){
           Final.erase(Final.begin()-i-1);
       }
    }
*/











 /*for (directions::nesw dir = directions::NORTH; dir <= directions::WEST; dir = directions::nesw(dir + 1))
    {
        if(canTravel(TopStack->getDirectionNode(dir))){//if top has another direction
            mazenodePtr = TopStack->getDirectionNode(dir); //mazenode points to available direction of top
            canTravels = true;
            break;
        }
    }
    if(canTravels == true){
        mazenodePtr->setVisited(); 
        nodesPtr.push(mazenodePtr);
        nodes.push_back(*mazenodePtr); 
    } 
    else{
       nodesPtr.pop();
       //mazenodePtr = nodesPtr.top();
    }  */   



    /* MazeNode* nextNode = a_maze.getFirstNode(); 
    std::vector<MazeNode> right; // to keep track of helperQ (tmp) nameless 
    std::vector<MazeNode> left;// to be a copy of right (tmp) nameless 
    std::queue<MazeNode *> helperQ;// queue of pointers 
    std::queue<vector<MazeNode> > nodesPtr; //to store nameless vectors 
    
    nextNode->setVisited();//set origin as visited 
    helperQ.push(a_maze.getFirstNode());//to move using pointers 
    right.push_back(* a_maze.getFirstNode());//add origin to vector

    while(!nodesPtr.empty() && nextNode != a_maze.getLastNode()){
         MazeNode* TopQ = helperQ.front();// front of queue of nodes 
         right = nodesPtr.front();// returns the front vector of queue to be added on 
         nodesPtr.pop();//removes the front vector
         helperQ.pop(); //to return to the diverging node  

         while(canTravel(TopQ->getDirectionNode(directions::NORTH)) || canTravel(TopQ->getDirectionNode(directions::EAST)) || canTravel(TopQ->getDirectionNode(directions::SOUTH)) || canTravel(TopQ->getDirectionNode(directions::WEST))){
             
                if(canTravel(TopQ->getDirectionNode(directions::NORTH))){//if top has other directions
                nextNode = TopQ->getDirectionNode(directions::NORTH); 
                nextNode->setVisited(); 
                helperQ.push(nextNode);
                right.push_back(*nextNode);
                }

                else if(canTravel(TopQ->getDirectionNode(directions::EAST))){
                nextNode = TopQ->getDirectionNode(directions::EAST); 
                nextNode->setVisited();
                helperQ.push(nextNode); 
                right.push_back(*nextNode);
                }

                else if(canTravel(TopQ->getDirectionNode(directions::SOUTH))){
                nextNode = TopQ->getDirectionNode(directions::SOUTH); 
                nextNode->setVisited();
                helperQ.push(nextNode);
                right.push_back(*nextNode);
                }


                else if(canTravel(TopQ->getDirectionNode(directions::WEST))){
                nextNode = TopQ->getDirectionNode(directions::WEST); 
                nextNode->setVisited();
                helperQ.push(nextNode);
                right.push_back(*nextNode);
                }
         } 
    } 
    nodesPtr.push(right);//add resulting vector to queue 
    for(int i=0; i < right.size()-1; i++){ //copy right to left up to divergence pt
        left.push_back(right[i]); 
    }
    nodesPtr.push(left);//add left to queue 
    
return nodesPtr.front(); */



/*
            int n = Final.size(); 
            std::pair<int, int> point = Final.at(n-1).getPos();//last of vector is top
            std::pair<int, int> point2 = Top->getPos();
            int x = std::abs(point.first - point2.first);
            int y = std::abs(point.second - point2.second);

        if(Final.empty() && x+y == 1){
           Final.push_back(*Top);
        }



        else if(Branches.empty()){
            std::vector<MazeNode> branch;  
            Top->resetVisited();
            branch.push_back(* Top);
            Branches.push_back(branch);
        }     

        else{
            for(int i = 0; i < Branches.size(); i++){
            std::pair<int, int> point1 = Branches[i][Branches[i].size()-1].getPos();
            std::pair<int, int> point2 = Top->getPos();
            int w = std::abs(point1.first - point2.first);
            int z = std::abs(point1.second - point2.second);
            if(w+z == 1){
                Top->resetVisited();
                Branches[i].push_back(*Top);
            }

            }
        }

        MazeNode * end = &Final[Final.size()-1];
        while(getNumberOfWalls(end) == 4){
            std::pair<int, int> point2 = Final[Final.size()-1].getPos();
            for(int i = 0; i < Branches.size(); i++){
            std::pair<int, int> point1 = Branches[i][0].getPos();
            
            int a = std::abs(point1.first - point2.first);
            int b = std::abs(point1.second - point2.second);
            if(a+b == 1){
                 Final.insert(Final.end(), Branches[i].begin(), Branches[i].end());
            }
         }    
    
        Final.pop_back();
       }        
*/