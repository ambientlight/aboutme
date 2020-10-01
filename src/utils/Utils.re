module List {
  let join = (~seperator, list) => 
    List.fold_left((a, b) => String.length(a) == 0 
      ? b 
      : (a ++ seperator ++ b), "", list);
};