#include<SFML/Graphics.hpp>
#include<thread>
#include<chrono>
#include<time.h>
#include<cstdlib>
#define HEIGHT 800
#define WIDTH 600

typedef struct{
    int vx,vy;
}Velocity;
typedef struct{
    sf::RectangleShape rect;
    Velocity vel;
}Agent;


sf::Vector2f getRandVel(){
    int randOption =  rand() % (4);
    switch(randOption){
        case 0:return sf::Vector2f(0,-1);
        case 1:return sf::Vector2f(-1,0);
        case 2:return sf::Vector2f(0,1);
        case 3:return sf::Vector2f(1,0);
    }
    return sf::Vector2f(-1,0);

}
void InitAgents(sf::RectangleShape agents[],int num){
    for(int i = 0 ; i < num ; i++){
        agents[i] = sf::RectangleShape(sf::Vector2f(1,1));
        agents[i].setPosition(HEIGHT / 2 , WIDTH / 2);
        int r = rand() / 256;
        int g = rand() / 256;
        int b = rand() / 256;
        agents[i].setFillColor(sf::Color(r,g,b,255));
    }
}
void moveAgent(sf::RectangleShape *agent , sf::RenderWindow *win){    
    sf::Vector2f dir = getRandVel();
    for(int i = 0 ; i < 10 ; i++){
        agent->move(dir);
        win->draw(*agent);
    }
}
int main(int argc , char* argv[]){
    int num_agents = 5;
    if(argc == 1){
        printf("Usage is ./RandomWalk {no of agents as integer} \nDefaulting no of Agents to 5");
    }
    else num_agents = std::atoi(argv[1]);
    
    sf::RenderWindow window(sf::VideoMode(HEIGHT , WIDTH), "Random Walk");
    window.setFramerateLimit(60);
    srand(time(NULL));
    sf::RectangleShape agents[num_agents];
    InitAgents(agents , num_agents);
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }        
        for(int i = 0 ; i < num_agents ; i++){
            moveAgent(&agents[i],&window);
            window.draw(agents[i]);
        }
        
        window.display();
    //    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

}