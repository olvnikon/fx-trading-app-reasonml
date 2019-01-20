type state = {prevBuy: float};

type action =
  | Buy(float);

let component = ReasonReact.reducerComponent("CurrencyPair");

let getMainCurrency = pair => Js.String.split(" ", pair)[0];

let make = (~pair: string, ~buy: float, ~sell: float, _children) => {
  ...component,
  initialState: () => {prevBuy: 0.0},
  reducer: (action, _state) =>
    switch (action) {
    | Buy(buy) => ReasonReact.Update({prevBuy: buy})
    },
  render: self => {
    /* self.send(Buy(buy));*/

    let isPositiveTrend = self.state.prevBuy < buy;
    let currency = getMainCurrency(pair);

    <section>
      <header> <h3> {ReasonReact.string(pair)} </h3> </header>
      <main>
        <SellRate rate=sell currency />
        <Triangle isPositiveTrend />
        <BuyRate rate=buy currency />
      </main>
    </section>;
  },
};
