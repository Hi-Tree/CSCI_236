/****************************************************************************************************************************

Title :       Solutions.cpp
Auhor :       Meri Khurshudyan 
Description : includes 4 different solutions to a maze 

****************************************************************************************************************************/

#include "Maze.hpp"
#include<stack>
#include<queue> 
#include <vector>

using namespace std;

namespace solutions
{

int getNumberOfWalls(MazeNode *a_node)
{
    int wall_counter = 0;
    for (directions::nesw dir = directions::NORTH; dir < directions::EAST; dir = directions::nesw(dir + 1))
    {
        if (a_node->getDirectionNode(dir) == nullptr || a_node->getDirectionNode(dir)->isWall() || a_node->getDirectionNode(dir)->isVisited())
        {
            wall_counter++;
        }
    }
    return wall_counter;
}

bool canTravel(MazeNode *a_node)
{
    if (a_node == nullptr || a_node->isVisited() || a_node->isWall())
    {
        return false;
    }
    return true;
}


/* ********************************** DFS ******************************************** */

std::vector<MazeNode> solveDFS(Maze &a_maze){   
    
    MazeNode* nextNode = a_maze.getFirstNode(); 
    std::vector<MazeNode> nodes; 
    std::stack<MazeNode*> nodesPtr;
    
    nextNode->setVisited();//set origin as visited 
    nodesPtr.push(a_maze.getFirstNode());//add origin to stack
    nodes.push_back(*a_maze.getFirstNode());//first node added to vector

     

    while(!nodesPtr.empty() && nextNode != a_maze.getLastNode()){
    MazeNode* nextNode = nodesPtr.top();


    if(canTravel(nextNode->getDirectionNode(directions::NORTH))){//if top has other directions
       nextNode = nextNode->getDirectionNode(directions::NORTH); 
       nextNode->setVisited(); 
       nodesPtr.push(nextNode); 
       nodes.push_back(*nextNode);
    }

     else if(canTravel(nextNode->getDirectionNode(directions::EAST))){
       nextNode = nextNode->getDirectionNode(directions::EAST); 
       nextNode->setVisited(); 
       nodesPtr.push(nextNode);
       nodes.push_back(*nextNode);
    }

    else if(canTravel(nextNode->getDirectionNode(directions::SOUTH))){
       nextNode = nextNode->getDirectionNode(directions::SOUTH); 
       nextNode->setVisited(); 
       nodesPtr.push(nextNode);
       nodes.push_back(*nextNode);
    }


    else if(canTravel(nextNode->getDirectionNode(directions::WEST))){
       nextNode = nextNode->getDirectionNode(directions::WEST); 
       nextNode->setVisited(); 
       nodesPtr.push(nextNode);
       nodes.push_back(*nextNode);
    }
     
    else{
        nodesPtr.pop();
        nodes.pop_back();    
    }
    
}
return nodes;
}

/* *************************************** BFS ********************************************** */
std::vector<MazeNode> solveBFS(Maze &a_maze){
    
    MazeNode * NextNode = a_maze.getFirstNode();
    std::vector<MazeNode*> Final;
    std::vector<MazeNode> Finals;
    std::queue<vector<MazeNode*> > Qvec;

   //set origin visited 
    NextNode->setVisited();
    Final.push_back(NextNode);
    Qvec.push(Final);

    
    while(!Qvec.empty() && Qvec.front().at(Qvec.front().size()-1) != a_maze.getLastNode()){
    
        std::vector<MazeNode*> TempV = Qvec.front();
        MazeNode * Top = TempV.back();
        Qvec.pop(); 
       
        for(directions::nesw dir = directions::NORTH; dir <= directions::WEST; dir = directions::nesw(dir + 1)){
               if(canTravel(Top->getDirectionNode(dir))){ 
                 
                NextNode = Top->getDirectionNode(dir);
                NextNode->setVisited();
                NextNode->setVisited();
                //if the point has another direction to be visited we pop back and create new vector 
                    TempV.push_back(NextNode);
                    Qvec.push(TempV);
                    TempV.pop_back();
                        
                    
               }
        }
    }


  for(int i = 0; i < Qvec.front().size(); i++){
        Finals.push_back(* Qvec.front()[i]);
   }



return Finals;
}

/* **************************************** DEF *************************************************** */
std::vector<MazeNode> solveDEF(Maze &a_maze)
{
    std::vector<MazeNode*> DeadEnds;//holds deadends as pointers 
    std::vector<MazeNode> Maze = a_maze.getNodes();//holds values of maze 

    //we go through the maze and add all deadends into a vector 
    for(int i = 0; i < Maze.size()-1; i++){
        if(getNumberOfWalls(&Maze.at(i)) == 3){
           DeadEnds.push_back(&Maze.at(i));
        }  
    }
    while(!DeadEnds.empty()){
         MazeNode* StartNode = DeadEnds.back();//start at one dead end
         MazeNode* NextNode2 = StartNode;//same as dead end originally 
         for(directions::nesw dir = directions::NORTH; dir <= directions::WEST; dir = directions::nesw(dir + 1)){
             while(getNumberOfWalls(NextNode2) != 1){
               if(canTravel(StartNode->getDirectionNode(dir))){ //it will find the single available path 
                NextNode2 = StartNode->getDirectionNode(dir);//then travel there 
                StartNode->setWall();//and set that wall
                StartNode = NextNode2;
               }
         }
    }
    
    DeadEnds.pop_back();//we will remove the first dead end
    
    }

    //************** now we implement BFS to do the rest of the work 

    MazeNode* nextNode = a_maze.getFirstNode(); 
    std::vector<MazeNode> nodes; 
    std::stack<MazeNode*> nodesPtr;
    
    nextNode->setVisited();//set origin as visited 
    nodesPtr.push(a_maze.getFirstNode());//add origin to stack
    nodes.push_back(*a_maze.getFirstNode());//first node added to vector

     

    while(!nodesPtr.empty() && nextNode != a_maze.getLastNode()){
    MazeNode* nextNode = nodesPtr.top();


    if(canTravel(nextNode->getDirectionNode(directions::NORTH))){//if top has other directions
       nextNode = nextNode->getDirectionNode(directions::NORTH); 
       nextNode->setVisited(); 
       nodesPtr.push(nextNode); 
       nodes.push_back(*nextNode);
    }

     else if(canTravel(nextNode->getDirectionNode(directions::EAST))){
       nextNode = nextNode->getDirectionNode(directions::EAST); 
       nextNode->setVisited(); 
       nodesPtr.push(nextNode);
       nodes.push_back(*nextNode);
    }

    else if(canTravel(nextNode->getDirectionNode(directions::SOUTH))){
       nextNode = nextNode->getDirectionNode(directions::SOUTH); 
       nextNode->setVisited(); 
       nodesPtr.push(nextNode);
       nodes.push_back(*nextNode);
    }


    else if(canTravel(nextNode->getDirectionNode(directions::WEST))){
       nextNode = nextNode->getDirectionNode(directions::WEST); 
       nextNode->setVisited(); 
       nodesPtr.push(nextNode);
       nodes.push_back(*nextNode);
    }
     
    else{
        nodesPtr.pop();
        nodes.pop_back();    
    }
    
}
return nodes;
}

/* *********************************************** Custom ************************************* */
std::vector<MazeNode> solveCustom(Maze &a_maze)
{
 MazeNode* nextNode = a_maze.getFirstNode(); 
    std::vector<MazeNode> nodes; 
    std::stack<MazeNode*> nodesPtr;
    
    nextNode->setVisited();//set origin as visited 
    nodesPtr.push(a_maze.getFirstNode());//add origin to stack
    nodes.push_back(*a_maze.getFirstNode());//first node added to vector

     

    while(!nodesPtr.empty() && nextNode != a_maze.getLastNode()){
    MazeNode* nextNode = nodesPtr.top();


    if(canTravel(nextNode->getDirectionNode(directions::NORTH))){//if top has other directions
       nextNode = nextNode->getDirectionNode(directions::NORTH); 
       nextNode->setVisited(); 
       nodesPtr.push(nextNode); 
       nodes.push_back(*nextNode);
    }

     else if(canTravel(nextNode->getDirectionNode(directions::EAST))){
       nextNode = nextNode->getDirectionNode(directions::EAST); 
       nextNode->setVisited(); 
       nodesPtr.push(nextNode);
       nodes.push_back(*nextNode);
    }

    else if(canTravel(nextNode->getDirectionNode(directions::SOUTH))){
       nextNode = nextNode->getDirectionNode(directions::SOUTH); 
       nextNode->setVisited(); 
       nodesPtr.push(nextNode);
       nodes.push_back(*nextNode);
    }


    else if(canTravel(nextNode->getDirectionNode(directions::WEST))){
       nextNode = nextNode->getDirectionNode(directions::WEST); 
       nextNode->setVisited(); 
       nodesPtr.push(nextNode);
       nodes.push_back(*nextNode);
    }
     
    else{
        nodesPtr.pop();
        nodes.pop_back();    
    }
    
}
return nodes;
}



/* ********************************** DFS recursive ******************************************** 

std::vector<MazeNode> solveRecursive(Maze &a_maze){
    std::vector<MazeNode> vector;
    MazeNode * CurrentNode = a_maze.getFirstNode();
    if(CurrentNode == a_maze.getLastNode()){
        return vector;
    }
    else{

    }

}

std::vector<MazeNode> helper(MazeNode &a_node, Maze &a_maze){
    MazeNode* nextNode = a_maze.getFirstNode(); 
    std::vector<MazeNode> nodes; 
    std::stack<MazeNode*> nodesPtr;
    

       if(canTravel(nextNode->getDirectionNode(directions::NORTH))){//if top has other directions
       nextNode = nextNode->getDirectionNode(directions::NORTH); 
       nextNode->setVisited(); 
       nodesPtr.push(nextNode); 
       nodes.push_back(*nextNode);
    }

     else if(canTravel(nextNode->getDirectionNode(directions::EAST))){
       nextNode = nextNode->getDirectionNode(directions::EAST); 
       nextNode->setVisited(); 
       nodesPtr.push(nextNode);
       nodes.push_back(*nextNode);
    }

    else if(canTravel(nextNode->getDirectionNode(directions::SOUTH))){
       nextNode = nextNode->getDirectionNode(directions::SOUTH); 
       nextNode->setVisited(); 
       nodesPtr.push(nextNode);
       nodes.push_back(*nextNode);
    }


    else if(canTravel(nextNode->getDirectionNode(directions::WEST))){
       nextNode = nextNode->getDirectionNode(directions::WEST); 
       nextNode->setVisited(); 
       nodesPtr.push(nextNode);
       nodes.push_back(*nextNode);
    }
}

*/


}



