#include "Maze.cpp"
#include <stack>
#include <queue>
#include <vector>
#include <cmath>

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


    std::vector<MazeNode> solveDFS(Maze &a_maze) //get direction node array returns the information (in an array) about a node's four neighbors
    {
        
        std::stack <MazeNode*> track_stack;
        std::vector <MazeNode> path_to_goal;

        MazeNode* current_node = a_maze.getFirstNode();

        //pointers?



        // push node to stack.
        // push node to vector
        // make current the top of the stack
        // if it has traversable children push any and all traversable children in NESW order.
        
        //pop from the top of the stack and make current top. Rinse repeat. This is all happening while stack is not empty

        track_stack.push(current_node);
        path_to_goal.push_back(*current_node);
        current_node->setVisited();


        while (!track_stack.empty() && (current_node != a_maze.getLastNode()) )
        {   

	        current_node = track_stack.top();
	        current_node->setVisited();

	        MazeNode* North_neighbor = current_node->getDirectionNode(directions::NORTH);
	        MazeNode* East_neighbor = current_node->getDirectionNode(directions::EAST);
	        MazeNode* South_neighbor = current_node->getDirectionNode(directions::SOUTH);
	        MazeNode* West_neighbor = current_node->getDirectionNode(directions::WEST);

   
            if (canTravel(North_neighbor))
            {
                track_stack.push(North_neighbor);
                path_to_goal.push_back(*North_neighbor);
            }

            else if(canTravel(East_neighbor))
            {
                track_stack.push(East_neighbor);
                path_to_goal.push_back(*East_neighbor);
            }

            else if(canTravel(South_neighbor))
            {
                track_stack.push(South_neighbor);
                path_to_goal.push_back(*South_neighbor);
            }

            else if(canTravel(West_neighbor))
            {
                track_stack.push(West_neighbor);
                path_to_goal.push_back(*West_neighbor);
            }

            else
            {
                track_stack.pop();
                path_to_goal.pop_back(); //This one line and line 106 changes it into a breadth first search. Line 106 will insert for the last node a second time. It was necessary for the BFS implementation but not for this one. So really only 
            }

            
            
        }

        path_to_goal.push_back(*a_maze.getLastNode()); //MUST DEREFERENCE!!!!!!!!!!
        return path_to_goal;

    }

 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    std::vector<MazeNode*> BFShelper(Maze &a_maze)
    {
        
        std::queue <MazeNode*> q_tracker;
        std::vector<MazeNode*> correct_route;
       
        MazeNode* start_node = a_maze.getFirstNode();
        MazeNode* current_node = start_node;

        q_tracker.push(current_node);
        correct_route.push_back(current_node);
        current_node->setVisited();

        while(!q_tracker.empty() && (q_tracker.front() != a_maze.getLastNode()))
        { 
            int i = 0;

            current_node = q_tracker.front();
            //cout << "something new please" << endl;
            q_tracker.pop();
            current_node->setVisited();

            MazeNode* North_neighbor = current_node->getDirectionNode(directions::NORTH);
            MazeNode* East_neighbor = current_node->getDirectionNode(directions::EAST);
            MazeNode* South_neighbor = current_node->getDirectionNode(directions::SOUTH);
            MazeNode* West_neighbor = current_node->getDirectionNode(directions::WEST);
            
            //cout << *(North_neighbor) << endl;
            //cout << *(East_neighbor) << endl;
            //I think it segfaults on first iteration trying to print South neighbor(prabably a nullptr). Look at the map

            if ( (North_neighbor == a_maze.getLastNode()) || (East_neighbor == a_maze.getLastNode()) || (South_neighbor == a_maze.getLastNode()) || (West_neighbor == a_maze.getLastNode()) )
            {

                break;
            }

            else
            {

                if (  (North_neighbor != nullptr) && canTravel(North_neighbor) ) //calling setVistor on a nullptr will segfault
                {


                    q_tracker.push(North_neighbor);
                    correct_route.push_back(North_neighbor);
                    //cout << *(North_neighbor) << endl;

                }

                if ( (East_neighbor != nullptr) && canTravel(East_neighbor) )
                {
                    
                    q_tracker.push(East_neighbor);
                    correct_route.push_back(East_neighbor);
                    //cout << *(East_neighbor) << endl;

                }

                if ( (South_neighbor != nullptr) && canTravel(South_neighbor) )
                {
                 

                    q_tracker.push(South_neighbor);
                    correct_route.push_back(South_neighbor);
                    //cout << *(South_neighbor) << endl;


                }

                if ( (West_neighbor != nullptr) && canTravel(West_neighbor) )
                {
                    
                            
                    q_tracker.push(West_neighbor);
                    correct_route.push_back(West_neighbor);
                    //cout << *(West_neighbor) << endl;
                 
                }

            }

        }
            correct_route.push_back(a_maze.getLastNode());
            //use your brain. If ymou didn't push this yet how could your algorithm get rid of the correct notes. This fixed the problem.
            //Also the help from Meri with the pair function fixed my seg fault.

            //shortest_route.push_back(q_tracker.front());
            //q_tracker.pop();
        return correct_route;
    }

    std::vector<MazeNode> solveBFS(Maze &a_maze)
    {

        std::vector<MazeNode*> shortest_route = BFShelper(a_maze); //in the beginning it is the vector with every node path but by the end it will be the shortest.
        std::vector<MazeNode> shortest_final_route;//not pointer
        //int i = shortest_route.size()-1;
        for(int i = shortest_route.size()-1; i > 0; i--)
        //while(i > 0)
        {

            //MazeNode* current_node = shortest_route[i];
            //MazeNode* previous_node = shortest_route[i-1];

            //the pair function includes (always has) members called first and second.
            //in this case first and second correspond to the x and y functions.

            //int difference_of_the_xs = abs( (current_node->getPos()).first - (previous_node->getPos()).first );
            //int difference_of_the_ys = abs( (current_node->getPos()).second - (previous_node->getPos()).second );

            std::pair<int, int> point1 = shortest_route.at(i)->getPos();
            std::pair<int, int> point2 = shortest_route.at(i-1)->getPos();

            int difference_of_the_xs = std::abs(point1.first - point2.first);
            int difference_of_the_ys = std::abs(point1.second - point2.second);

            //if( ( (difference_of_the_xs == 1) && (difference_of_the_ys == 0) ) ||  ( (difference_of_the_xs == 0)  &&  (difference_of_the_ys == 1) ) )
            if (difference_of_the_xs + difference_of_the_ys != 1 )
            {
                //erase previous_node

                //int index_from_beginning = shortest_route.size() - i + 1 ;
                shortest_route.erase(shortest_route.begin()+i-1); //+ index_from_beginning);

            }


        }

        for(int i = 0; i < shortest_route.size(); i++){//pointer 
            shortest_final_route.push_back(* shortest_route.at(i));//dereferenced 
        }
        return shortest_final_route;
    }


/* **************************************** DEF ***************************** */

    std::vector<MazeNode> solveDEF(Maze &a_maze) // yes lets do wall counter 
    {
            std::vector<MazeNode*> Dead_Ends_of_Maze;
            std::vector<MazeNode> MazeNodes = a_maze.getNodes();// returns all maze nodes

    
            for(int i = 0; i < MazeNodes.size()-1; i++){
                if(getNumberOfWalls(&MazeNodes.at(i)) == 3){// we search for dead ends and save them
                    Dead_Ends_of_Maze.push_back(&MazeNodes.at(i));
                }  
            }


            while(!Dead_Ends_of_Maze.empty()){
                    MazeNode* First_dead_end = Dead_Ends_of_Maze.back();
                    MazeNode* Next_available_Node = First_dead_end;
                    for(directions::nesw dir = directions::NORTH; dir <= directions::WEST; dir = directions::nesw(dir + 1)){
                        while(getNumberOfWalls(Next_available_Node) != 1){
                        if(canTravel(First_dead_end->getDirectionNode(dir))){ 
                        Next_available_Node = First_dead_end->getDirectionNode(dir);
                        First_dead_end->setWall();
                        First_dead_end = Next_available_Node;
                        }
                     }
                 }
    
             Dead_Ends_of_Maze.pop_back();
    
            }

    //***********************************************************************
        std::vector<MazeNode*> shortest_route = BFShelper(a_maze); //in the beginning it is the vector with every node path but by the end it will be the shortest.
        std::vector<MazeNode> shortest_final_route;//not pointer
        //int i = shortest_route.size()-1;
        for(int i = shortest_route.size()-1; i > 0; i--)
        //while(i > 0)
        {

            //MazeNode* current_node = shortest_route[i];
            //MazeNode* previous_node = shortest_route[i-1];

            //the pair function includes (always has) members called first and second.
            //in this case first and second correspond to the x and y functions.

            //int difference_of_the_xs = abs( (current_node->getPos()).first - (previous_node->getPos()).first );
            //int difference_of_the_ys = abs( (current_node->getPos()).second - (previous_node->getPos()).second );

            std::pair<int, int> point1 = shortest_route.at(i)->getPos();
            std::pair<int, int> point2 = shortest_route.at(i-1)->getPos();

            int difference_of_the_xs = std::abs(point1.first - point2.first);
            int difference_of_the_ys = std::abs(point1.second - point2.second);

            //if( ( (difference_of_the_xs == 1) && (difference_of_the_ys == 0) ) ||  ( (difference_of_the_xs == 0)  &&  (difference_of_the_ys == 1) ) )
            if (difference_of_the_xs + difference_of_the_ys != 1 )
            {
                //erase previous_node

                //int index_from_beginning = shortest_route.size() - i + 1 ;
                shortest_route.erase(shortest_route.begin()+i-1); //+ index_from_beginning);

            }


        }

        for(int i = 0; i < shortest_route.size(); i++){//pointer 
            shortest_final_route.push_back(* shortest_route.at(i));//dereferenced 
        }
        return shortest_final_route;
}

            
            

}