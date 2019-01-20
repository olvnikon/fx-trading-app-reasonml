let mapChunk = (index: int, chunk) => {
  <span key={string_of_int(index)}> {ReasonReact.string(chunk)} </span>;
};

let mapChunks = chunks => Array.mapi(mapChunk, chunks);

let splitByChunks = value => {
  value
  |> Js.String.match([%re "/.{1,2}/g"])
  |> (
    result =>
      switch (result) {
      | None => [|"00"|]
      | Some(result) => result
      }
  );
};

let mapLeftSide = leftSide =>
  <span> {ReasonReact.string(leftSide ++ ".")} </span>;

let mapRightSide = rightSide =>
  splitByChunks(rightSide) |> mapChunks |> ReasonReact.array;

let splitRateLeftRight = rate => {
  let result = Js.String.split(".", string_of_float(rate));
  (result[0], result[1]);
};

let mapRate = (rate: float) => {
  let (leftSide, rightSide) = splitRateLeftRight(rate);
  <span> {mapLeftSide(leftSide)} {mapRightSide(rightSide)} </span>;
};
