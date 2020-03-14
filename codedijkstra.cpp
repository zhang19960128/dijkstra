#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
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
  std::list<int> shortestvisitsequence;
  std::list<double> shortestvisitdistance;
  std::vector<int> visited(nodenumber,0);
  std::vector<double> candidateshortest;
  std::vector<int> candidatenewnode;
  std::vector<int> candidatepredecessor;
  int newshortestnode;
  int index;
  double newshortestdistance;
  do{
    newshortestdistance=1e15;
    for(struct{std::list<double>::iterator stdis;std::list<int>::iterator stnode;} a={shortestdistance.begin(),shortestsequence.begin()};a.stnode!=shortestsequence.end();a.stdis++,a.stnode++){
	for(struct{std::list<double>::iterator stdis;std::list<int>::iterator stnode} b={this->distance[*(a.stnode)].begin(),this->edges[*(a.stnode)].begin()},b.stnode!=this->edges[*(a.stnode)].end();b.stdis++,b.stnode++){
	  if(visited[*(b.stnode)]==0){
	    candidateshortest.push_back(*(b.stdis)+*(a.stdis));
	    candidatenewnode.push_back(*(b.stnode));
	    candidatepredecessor.push_back(*(a.stnode));
	  }
	  else{
	  }
	}
    }
    index=std::min_element(candidateshortest.being(),candidateshortest.end())-candidateshortest.begin();
    this->shortestdistance[candidatenewnode[index]]=candidateshortest[index];
    /*get the shortest path*/
    for(std::list<int>::iterator a=this->shortestpath[candidatepredecessor[index]].begin();a!=this->shortestpath[candidatepredecessor[index]].end();a++){
    	this->shortestpath[candidatenewnode[index]].push_back(*a);
    }
    this->shortestpath[candidatenewnode[index]].push_back(candidatepredecessor[index]);
    visited[candidatenewnode[index]]==1;
    shortestvisitsequence.push_back(candidatenewnode[index]);
  }while(shortestvisitsequence.size()!=this->nodenumber);
}
int main(){
  graph g("dijkstra.txt");
  g.dijkstra();
}
