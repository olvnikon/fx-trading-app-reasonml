let component = ReasonReact.statelessComponent("Rate");

let make = (~rate: float, ~header: string, _children) => {
  ...component,
  render: _self => {
    <section>
      <header> {ReasonReact.string(header)} </header>
      <main> {RateHelpers.mapRate(rate)} </main>
    </section>;
  },
};
