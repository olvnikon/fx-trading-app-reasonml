type state = {
  currencyPairs: array(HomeMocks.pair),
  timerId: ref(option(Js.Global.intervalId)),
};
type action =
  | RefreshPairs;

let component = ReasonReact.reducerComponent("Home");

let make = _children => {
  ...component,
  initialState: () => {
    currencyPairs: HomeMocks.currencyPairsMock,
    timerId: ref(None),
  },
  didMount: self => {
    self.state.timerId :=
      Some(
        Js.Global.setInterval(
          () => self.send(RefreshPairs),
          HomeConstants.refreshTime,
        ),
      );
  },
  willUnmount: self => {
    switch (self.state.timerId^) {
    | Some(id) => Js.Global.clearInterval(id)
    | None => ()
    };
  },
  reducer: (action, state) =>
    switch (action) {
    | RefreshPairs =>
      ReasonReact.Update({
        ...state,
        currencyPairs: Array.map(HomeHelpers.mapPairs, state.currencyPairs),
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
