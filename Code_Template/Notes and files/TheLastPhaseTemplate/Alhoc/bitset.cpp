bitset<mx>bt;
bt.set()  all 1; bt.reset() //all 0
bt.count() total 1; bt._Find_first() first 1 idx
bt._Find_next() // next one bit
for (int i = bt._Find_first(); i < mx; i = bt._Find_next()) // for traversing all 1 node
