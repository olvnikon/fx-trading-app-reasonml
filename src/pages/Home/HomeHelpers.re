let multiplyByRandomValue = (max: float, min: float, value: float) =>
  float_of_string(
    Js.Float.toFixedWithPrecision(
      value *. (Js.Math.random() *. (min -. max) +. max),
      ~digits=5,
    ),
  );

let shouldPairUpdate = () =>
  Js.Math.random() < HomeConstants.pairChangeProbability;

let multiplyByRandom =
  multiplyByRandomValue(
    HomeConstants.minMultiplier,
    HomeConstants.maxMultiplier,
  );

let getPairWithUpdatedRate = (HomeMocks.Pair(pair, buy, sell)) =>
  HomeMocks.Pair(pair, multiplyByRandom(buy), multiplyByRandom(sell));

let mapPairs = pair =>
  shouldPairUpdate() ? getPairWithUpdatedRate(pair) : pair;
