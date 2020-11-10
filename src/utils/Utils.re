module List {
  let join = (~seperator, list) => 
    List.fold_left((a, b) => String.length(a) == 0 
      ? b 
      : (a ++ seperator ++ b), "", list);
};

module Array {
  let pairwise = (arr: array('a)): array(array('a)) => {
    arr
    |. Belt.Array.reduceWithIndex([||], (tar, _, idx) => 
      idx mod 2 == 0 
        ? Array.concat([tar, [|Js.Array.slice(~start=idx, ~end_=idx + 2, arr)|]]) 
        : tar
    )
  };
}