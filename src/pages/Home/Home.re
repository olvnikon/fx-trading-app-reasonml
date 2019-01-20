type pair =
  | Pair(string, float, float);

let component = ReasonReact.statelessComponent("Home");

let currencyPairsMock = [|
  Pair("USD CHF", 0.99143, 0.99043),
  Pair("GBP USD", 1.28495, 1.2836),
  Pair("GBP CHF", 1.27378, 1.27147),
  Pair("EUR SEK", 9.632, 9.6055),
  Pair("USD JPY", 110.467, 110.417),
  Pair("EUR JPY", 120.589, 120.491),
|];

let make = _children => {
  ...component,
  render: _self => {
    <main>
      {ReasonReact.array(
         Array.mapi(
           (index, Pair(pair, buy, sell)) =>
             <CurrencyPair key={string_of_int(index)} pair buy sell />,
           currencyPairsMock,
         ),
       )}
    </main>;
  },
};
