type state = {currencyPairs: array(HomeMocks.pair)};
type action =
  | RefreshPairs;

let component = ReasonReact.reducerComponent("Home");

let make = _children => {
  ...component,
  initialState: () => {currencyPairs: HomeMocks.currencyPairsMock},
  didMount: _self => {
    ();
  },
  reducer: (action, state) =>
    switch (action) {
    | RefreshPairs =>
      ReasonReact.Update({
        currencyPairs:
          Array.map(pair => HomeHelpers.mapPairs(pair), state.currencyPairs),
      })
    },
  render: self => {
    <main>
      {ReasonReact.array(
         Array.mapi(
           (index, HomeMocks.Pair(pair, buy, sell)) =>
             <CurrencyPair key={string_of_int(index)} pair buy sell />,
           self.state.currencyPairs,
         ),
       )}
    </main>;
  },
};
