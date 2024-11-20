
int dTable[vCount];

for(i = 0; i < vCount; i++) {
   dTable[i] = std::numeric_limits<double>::infinity();
}
dTable[source] = 0;


//predecessor table holds value of previous node
int predecessor[vCount];
