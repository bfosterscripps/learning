function initData(n){
  var tempId = new Array(n);
  for (var i = 0; i < n; i++)
    tempId[i] = i;
  return tempId;
}


function root(i){
  while (i !== id[i])
    i = id[i];
  return i;
}

function quickFindUnion(p,q){
  var pid = id[p],
      qid = id[q];
  for (var i = 0; i < id.length; i++){
    if(id[i] === pid)
      id[i] = qid;
  }
}

function quickUnion(p, q){
  var i = root(p),
      j = root(q);
  id[i] = j;
}

function weightedQuickUnion(p, q){
  var i = root(p),
      j = root(q);
  if (i === j)
    return;
  console.log('sizes', sizes);
  if (sizes[i] < sizes[j]){
    id[i] = j;
    sizes[j] += sizes[i];
  } else {
    id[j] = i;
    sizes[i] += sizes[j];
  }
}

function isPossibleWeightedUnion(arr){
//   Which of the following id[] array(s) could be the result of running
// the weighted quick union algorithm on a set of 10 items?
//   Recall that our weighted quick union algorithm uses union by size
// (number of nodes) and not union by height.

  var lgN = Math.log(n) / Math.LN2;

}


var n = 10,
    id = initData(n),
    sizes = new Array();

for(var i = 0; i < n; i++){
  sizes[i] = 1;
}


console.log('starting id: ', id);




console.log('ending id: ', id);




// previous attempts


// Attempt 3, Question 2
/*
(seed = 303013)
Give the id[] array that results from the following sequence of 9 union
operations on a set of 10 items using the weighted quick-union algorithm from lecture.

    2-5 0-4 2-7 1-5 9-3 5-6 0-3 0-1 6-8

Your answer should be a sequence of 10 integers, separated by whitespace.

Recall: when joining two trees of equal size, our weighted quick union convention is to
make the root of the second tree point to the root of the first tree. Also, our weighted
quick union algorithm performs union by size (number of nodes) -  not union by height -
and does not do path compression.
*/
// weightedQuickUnion(2, 5);
// weightedQuickUnion(0, 4);
// weightedQuickUnion(2, 7);
// weightedQuickUnion(1, 5);
// weightedQuickUnion(9, 3);
// weightedQuickUnion(5, 6);
// weightedQuickUnion(0, 3);
// weightedQuickUnion(0, 1);
// weightedQuickUnion(6, 8);

// Attempt 3, Question 1
/*
(seed = 911001)
Give the id[] array that results from the following sequence of 6 union
operations on a set of 10 items using the quick-find algorithm.

    3-6 6-0 4-7 9-7 4-8 4-0

Your answer should be a sequence of 10 integers, separated by whitespace.

Recall: our quick-find convention for the union operation p-q is to change id[p]
(and perhaps some other entries) but not id[q].
*/
// quickFindUnion(3, 6);
// quickFindUnion(6, 0);
// quickFindUnion(4, 7);
// quickFindUnion(9, 7);
// quickFindUnion(4, 8);
// quickFindUnion(4, 0);

// Attempt 2, question 1
/*
(seed = 131070)
Give the id[] array that results from the following sequence of 6 union
operations on a set of 10 items using the quick-find algorithm.

    quickFindUnion(0, 8);
quickFindUnion(3, 4);
quickFindUnion(2, 1);
quickFindUnion(0, 5);
quickFindUnion(7, 8);
7-9

Your answer should be a sequence of 10 integers, separated by whitespace.

Recall: our quick-find convention for the union operation p-q is to change id[p]
(and perhaps some other entries) but not id[q].
*/
// quickFindUnion(0,8);
// quickFindUnion(3,4);
// quickFindUnion(2,1);
// quickFindUnion(0,5);
// quickFindUnion(7,8);
// quickFindUnion(7,9);

// Attempt 2, question 2
/*
(seed = 608030)
Give the id[] array that results from the following sequence of 9 union
operations on a set of 10 items using the weighted quick-union algorithm from lecture.

    quickFindUnion(9, 2);
quickFindUnion(5, 2);
quickFindUnion(1, 8);
quickFindUnion(5, 7);
quickFindUnion(4, 3);
quickFindUnion(0, 7);
quickFindUnion(1, 3);
quickFindUnion(2, 4);
8-6

Your answer should be a sequence of 10 integers, separated by whitespace.

Recall: when joining two trees of equal size, our weighted quick union convention is to
make the root of the second tree point to the root of the first tree. Also, our weighted
quick union algorithm performs union by size (number of nodes) -  not union by height -
and does not do path compression.
*/

// weightedQuickUnion(9,2);
// weightedQuickUnion(5,2);
// weightedQuickUnion(1,8);
// weightedQuickUnion(5,7);
// weightedQuickUnion(4,3);
// weightedQuickUnion(0,7);
// weightedQuickUnion(1,3);
// weightedQuickUnion(2,4);
// weightedQuickUnion(8,6);
