module List {
  let join = (~seperator, list) => 
    List.fold_left((a, b) => a ++ seperator ++ b, "", list);
};