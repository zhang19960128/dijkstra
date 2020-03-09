#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <sstream>
class graph{
  public:
    graph();
    graph(int number);
    graph(std::string graphfile);
    void dijkstra();
  private:
    int nodenumber;
    std::vector<int> nodevector;
    std::vector<std::list<int> > edges;
    std::vector<std::list<double> > distance;
    std::vector<double> shortestdistance;
    std::vector<std::list<int> > shortestpath;
};
graph::graph(int number){
  nodevector=std::vector<int>(number,0);
  edges=std::vector<std::list<int> > (number,std::list<int>(0,0));
  distance=std::vector<std::list<double> >(number,std::list<double>(0,0.0));
  shortestdistance=std::vector<double>(number,0.0);
  shortestpath=std::vector<std::list<int> >(number,std::list<int>(0,0.0));
};
graph::graph(std::string graphfile){
  std::fstream fs;
  fs.open(graphfile.c_str(),std::fstream::in);
  std::string tempstring;
  std::stringstream tempstream;
  nodenumber=0;
  while(getline(fs,tempstring)){
    tempstream.clear();
    tempstream.str(tempstring);
    tempstream>>nodenumber;
  }
  fs.close();
  nodevector=std::vector<int>(nodenumber,0);
  shortestdistance=std::vector<double>(nodenumber,0.0);
  shortestpath=std::vector<std::list<int> >(nodenumber,std::list<int>(0,0));
  edges=std::vector<std::list<int> > (nodenumber,std::list<int>(0,0));
  distance=std::vector<std::list<double> >(nodenumber,std::list<double>(0,0.0));
  fs.open(graphfile.c_str(),std::fstream::in);
  int tempint;
  int node;
  char coma;
  double dist;
  while(getline(fs,tempstring)){
    tempstream.clear();
    tempstream.str(tempstring);
    tempstream>>tempint;
    while(!tempstream.eof()){
    	tempstream>>node;
	tempstream>>coma;
	tempstream>>dist;
	edges[tempint-1].push_back(node);
	distance[tempint-1].push_back(dist);
    }
  }
}
void graph::dijkstra(){
  std::list<double> shortestdistance;
  std::list<int> shortestsequence;
  std::vector<int> visited(nodenumber,0);
  int newshortestnode;
  double newshortestdistance;
  do{
    newshortestdistance=1e15;
    for(struct{std::list<double>::iterator stdis;std::list<int>::iterator stnode;} a={shortestdistance.begin(),shortestsequence.begin()};a.stnode!=shortestsequence.end();a.stdis++,a.stnode++){

    }
  }while(shortestdistance.size()!=this->nodenumber);
}
int main(){
  graph G("dijkstra.txt");
}
