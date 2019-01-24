type state = {prevBuy: float};
type retainedProps = {buy: float};

let component =
  ReasonReact.statelessComponentWithRetainedProps("CurrencyPair");

let getMainCurrency = pair => Js.String.split(" ", pair)[0];

let make = (~pair: string, ~buy: float, ~sell: float, _children) => {
  ...component,
  retainedProps: buy,
  render: self => {
    let isPositiveTrend = self.retainedProps < buy;
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
