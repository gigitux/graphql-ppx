[@ocaml.ppx.context
  {
    tool_name: "migrate_driver",
    include_dirs: [],
    load_path: [],
    open_modules: [],
    for_package: None,
    debug: false,
    use_threads: false,
    use_vmthreads: false,
    recursive_types: false,
    principal: false,
    transparent_modules: false,
    unboxed_types: false,
    unsafe_string: false,
    cookies: [],
  }
];
type scalars = {
  string,
  int,
};

type dog = {
  name: string,
  barkVolume: float,
};

type oneFieldQuery = {nullableString: option(string)};
module MyQuery' = {
  module Raw = {
    type t_variousScalars = {
      .
      "string": string,
      "int": int,
    };
    type t = {. "variousScalars": t_variousScalars};
    type t_variables = Js.Json.t;
  };
  let query = "query   {\nvariousScalars  {\nstring  \nint  \n}\n\n}\n";
  type t = {. "variousScalars": scalars};
  type t_variables = Js.Json.t;
  let parse: Raw.t => t =
    value => {
      let variousScalars = {
        let value = value##variousScalars;
        (
          {
            let int = {
              let value = value##int;
              value;
            }
            and string = {
              let value = value##string;
              value;
            };
            {string, int};
          }: scalars
        );
      };
      {"variousScalars": variousScalars};
    };
  let serialize: t => Raw.t =
    value => {
      let variousScalars = {
        let value = value##variousScalars;
        let int = {
          let value = (value: scalars).int;
          value;
        }
        and string = {
          let value = (value: scalars).string;
          value;
        };
        {"string": string, "int": int};
      };
      {"variousScalars": variousScalars};
    };
  let make = () => {
    "query": query,
    "variables": Js.Json.null,
    "parse": parse,
  };
  module Z__INTERNAL = {
    type root = t;
    type nonrec graphql_module;
    /****--- GraphQL PPX Module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module MyQuery {
  // This is the stringified representation of your query, which gets sent to the server.
  let query: string;

  // This is the main type of the result you will get back.
  // You can hover above the identifier key (e.g. query or mutation) to see the fully generated type for your module.
  type t;

  // This function turns your raw result from the server into the reason/ocaml representation of that result.
  // Depending on your graphql client library, this process should happen automatically for you.
  let parse: Raw.t => t;

  // This function will prepare your data for sending it back to the server.
  // Depending on your graphql client library, this process should happen automatically for you.
  let serialize: t => Raw.t;

  // The definition tuple is primarily used to interact with client libraries.
  // The types are equivalent to: (parse, query, serialize).
  // Your client library will use these values to provide the properly parsed / serialized data for you.
  let definition: (
    Raw.t => t,
    string,
    t => Raw.t
  );

  // This is the representation of your raw result coming from the server.
  // It should not be necessary to access the types inside for normal use cases.
  module Raw: { type t; };
}
```*/
    let graphql_module: graphql_module = Obj.magic(0);
  };
};
module MyQuery = {
  include MyQuery';
  let self:
    module GraphQL_PPX.Query with
      type t_variables = MyQuery'.t_variables and
      type Raw.t_variables = MyQuery'.Raw.t_variables and
      type t = MyQuery'.t and
      type Raw.t = MyQuery'.Raw.t =
    (module MyQuery');
};
module OneFieldQuery' = {
  module Raw = {
    type t_variousScalars = {. "nullableString": Js.Nullable.t(string)};
    type t = {. "variousScalars": t_variousScalars};
    type t_variables = Js.Json.t;
  };
  let query = "query   {\nvariousScalars  {\nnullableString  \n}\n\n}\n";
  type t_variousScalars = {nullableString: option(string)};
  type t = {. "variousScalars": t_variousScalars};
  type t_variables = Js.Json.t;
  let parse: Raw.t => t =
    value => {
      let variousScalars = {
        let value = value##variousScalars;
        (
          {
            let nullableString = {
              let value = value##nullableString;
              switch (Js.toOption(value)) {
              | Some(value) => Some(value)
              | None => None
              };
            };
            {nullableString: nullableString};
          }: t_variousScalars
        );
      };
      {"variousScalars": variousScalars};
    };
  let serialize: t => Raw.t =
    value => {
      let variousScalars = {
        let value = value##variousScalars;
        let nullableString = {
          let value = (value: t_variousScalars).nullableString;
          switch (value) {
          | Some(value) => Js.Nullable.return(value)
          | None => Js.Nullable.null
          };
        };
        {"nullableString": nullableString};
      };
      {"variousScalars": variousScalars};
    };
  let make = () => {
    "query": query,
    "variables": Js.Json.null,
    "parse": parse,
  };
  module Z__INTERNAL = {
    type root = t;
    type nonrec graphql_module;
    /****--- GraphQL PPX Module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module OneFieldQuery {
  // This is the stringified representation of your query, which gets sent to the server.
  let query: string;

  // This is the main type of the result you will get back.
  // You can hover above the identifier key (e.g. query or mutation) to see the fully generated type for your module.
  type t;

  // This function turns your raw result from the server into the reason/ocaml representation of that result.
  // Depending on your graphql client library, this process should happen automatically for you.
  let parse: Raw.t => t;

  // This function will prepare your data for sending it back to the server.
  // Depending on your graphql client library, this process should happen automatically for you.
  let serialize: t => Raw.t;

  // The definition tuple is primarily used to interact with client libraries.
  // The types are equivalent to: (parse, query, serialize).
  // Your client library will use these values to provide the properly parsed / serialized data for you.
  let definition: (
    Raw.t => t,
    string,
    t => Raw.t
  );

  // This is the representation of your raw result coming from the server.
  // It should not be necessary to access the types inside for normal use cases.
  module Raw: { type t; };
}
```*/
    let graphql_module: graphql_module = Obj.magic(0);
  };
};
module OneFieldQuery = {
  include OneFieldQuery';
  let self:
    module GraphQL_PPX.Query with
      type t_variables = OneFieldQuery'.t_variables and
      type Raw.t_variables = OneFieldQuery'.Raw.t_variables and
      type t = OneFieldQuery'.t and
      type Raw.t = OneFieldQuery'.Raw.t =
    (module OneFieldQuery');
};
module ExternalFragmentQuery = {
  module Fragment' = {
    let query = "fragment Fragment on VariousScalars   {\nstring  \nint  \n}\n";
    module Raw = {
      type t = {
        .
        "string": string,
        "int": int,
      };
      type nonrec t_VariousScalars = t;
    };
    type t = {
      string,
      int,
    };
    type nonrec t_VariousScalars = t;
    let parse = (value: Raw.t): t => {
      let int = {
        let value = value##int;
        value;
      }
      and string = {
        let value = value##string;
        value;
      };
      {string, int};
    };
    let serialize: t => Raw.t =
      value => {
        let int = {
          let value = (value: t).int;
          value;
        }
        and string = {
          let value = (value: t).string;
          value;
        };
        {"string": string, "int": int};
      };
    let name = "Fragment";
    module Z__INTERNAL = {
      type root = t;
      type nonrec graphql;
      /**```
VariousScalars {
  nullableString: String
  string: String!
  nullableInt: Int
  int: Int!
  nullableFloat: Float
  float: Float!
  nullableBoolean: Boolean
  boolean: Boolean!
  nullableID: ID
  id: ID!
}
```*/
      let graphql: graphql = Obj.magic(0);
      type nonrec graphql_module;
      /****--- GraphQL PPX Module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module ExternalFragmentQuery {
  // This is the stringified representation of your query, which gets sent to the server.
  let query: string;

  // This is the main type of the result you will get back.
  // You can hover above the identifier key (e.g. query or mutation) to see the fully generated type for your module.
  type t;

  // This function turns your raw result from the server into the reason/ocaml representation of that result.
  // Depending on your graphql client library, this process should happen automatically for you.
  let parse: Raw.t => t;

  // This function will prepare your data for sending it back to the server.
  // Depending on your graphql client library, this process should happen automatically for you.
  let serialize: t => Raw.t;

  // The definition tuple is primarily used to interact with client libraries.
  // The types are equivalent to: (parse, query, serialize).
  // Your client library will use these values to provide the properly parsed / serialized data for you.
  let definition: (
    Raw.t => t,
    string,
    t => Raw.t
  );

  // This is the representation of your raw result coming from the server.
  // It should not be necessary to access the types inside for normal use cases.
  module Raw: { type t; };
}
```*/
      let graphql_module: graphql_module = Obj.magic(0);
    };
  };
  module Fragment = {
    include Fragment';
    let self:
      module GraphQL_PPX.Fragment with
        type t = Fragment'.t and type Raw.t = Fragment'.Raw.t =
      (module Fragment');
  };
  module Untitled1' = {
    module Raw = {
      type t = {. "variousScalars": Fragment.Raw.t};
      type t_variables = Js.Json.t;
    };
    let query =
      (
        ("query   {\nvariousScalars  {\n..." ++ Fragment.name)
        ++ "   \n}\n\n}\n"
      )
      ++ Fragment.query;
    type t = {. "variousScalars": Fragment.t};
    type t_variables = Js.Json.t;
    let parse: Raw.t => t =
      value => {
        let variousScalars = {
          let value = value##variousScalars;
          Fragment.parse(value);
        };
        {"variousScalars": variousScalars};
      };
    let serialize: t => Raw.t =
      value => {
        let variousScalars = {
          let value = value##variousScalars;
          Fragment.serialize(value);
        };
        {"variousScalars": variousScalars};
      };
    let make = () => {
      "query": query,
      "variables": Js.Json.null,
      "parse": parse,
    };
    module Z__INTERNAL = {
      type root = t;
      type nonrec graphql_module;
      /****--- GraphQL PPX Module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module ExternalFragmentQuery {
  // This is the stringified representation of your query, which gets sent to the server.
  let query: string;

  // This is the main type of the result you will get back.
  // You can hover above the identifier key (e.g. query or mutation) to see the fully generated type for your module.
  type t;

  // This function turns your raw result from the server into the reason/ocaml representation of that result.
  // Depending on your graphql client library, this process should happen automatically for you.
  let parse: Raw.t => t;

  // This function will prepare your data for sending it back to the server.
  // Depending on your graphql client library, this process should happen automatically for you.
  let serialize: t => Raw.t;

  // The definition tuple is primarily used to interact with client libraries.
  // The types are equivalent to: (parse, query, serialize).
  // Your client library will use these values to provide the properly parsed / serialized data for you.
  let definition: (
    Raw.t => t,
    string,
    t => Raw.t
  );

  // This is the representation of your raw result coming from the server.
  // It should not be necessary to access the types inside for normal use cases.
  module Raw: { type t; };
}
```*/
      let graphql_module: graphql_module = Obj.magic(0);
    };
  };
  module Untitled1 = {
    include Untitled1';
    let self:
      module GraphQL_PPX.Query with
        type t_variables = Untitled1'.t_variables and
        type Raw.t_variables = Untitled1'.Raw.t_variables and
        type t = Untitled1'.t and
        type Raw.t = Untitled1'.Raw.t =
      (module Untitled1');
  };
};
module InlineFragmentQuery' = {
  module Raw = {
    type t_dogOrHuman_Dog = {
      .
      "__typename": string,
      "name": string,
      "barkVolume": float,
    };
    type t_dogOrHuman;
    type t = {. "dogOrHuman": t_dogOrHuman};
    type t_variables = Js.Json.t;
  };
  let query = "query   {\ndogOrHuman  {\n__typename\n...on Dog   {\nname  \nbarkVolume  \n}\n\n}\n\n}\n";
  type t_dogOrHuman_Dog = {
    name: string,
    barkVolume: float,
  };
  type t_dogOrHuman = [
    | `FutureAddedValue(Js.Json.t)
    | `Dog(t_dogOrHuman_Dog)
  ];
  type t = {. "dogOrHuman": t_dogOrHuman};
  type t_variables = Js.Json.t;
  let parse: Raw.t => t =
    value => {
      let dogOrHuman = {
        let value = value##dogOrHuman;
        let typename: string =
          Obj.magic(Js.Dict.unsafeGet(Obj.magic(value), "__typename"));
        (
          switch (typename) {
          | "Dog" =>
            `Dog(
              {
                let value: Raw.t_dogOrHuman_Dog = Obj.magic(value);
                (
                  {
                    let barkVolume = {
                      let value = value##barkVolume;
                      value;
                    }
                    and name = {
                      let value = value##name;
                      value;
                    };
                    {name, barkVolume};
                  }: t_dogOrHuman_Dog
                );
              },
            )
          | _ => `FutureAddedValue(Obj.magic(value): Js.Json.t)
          }: t_dogOrHuman
        );
      };
      {"dogOrHuman": dogOrHuman};
    };
  let serialize: t => Raw.t =
    value => {
      let dogOrHuman = {
        let value = value##dogOrHuman;
        switch (value) {
        | `Dog(value) => (
            Obj.magic(
              {
                let barkVolume = {
                  let value = (value: t_dogOrHuman_Dog).barkVolume;
                  value;
                }
                and name = {
                  let value = (value: t_dogOrHuman_Dog).name;
                  value;
                };
                {"__typename": "Dog", "name": name, "barkVolume": barkVolume};
              },
            ): Raw.t_dogOrHuman
          )
        | `FutureAddedValue(value) => (Obj.magic(value): Raw.t_dogOrHuman)
        };
      };
      {"dogOrHuman": dogOrHuman};
    };
  let make = () => {
    "query": query,
    "variables": Js.Json.null,
    "parse": parse,
  };
  module Z__INTERNAL = {
    type root = t;
    type nonrec graphql_module;
    /****--- GraphQL PPX Module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module InlineFragmentQuery {
  // This is the stringified representation of your query, which gets sent to the server.
  let query: string;

  // This is the main type of the result you will get back.
  // You can hover above the identifier key (e.g. query or mutation) to see the fully generated type for your module.
  type t;

  // This function turns your raw result from the server into the reason/ocaml representation of that result.
  // Depending on your graphql client library, this process should happen automatically for you.
  let parse: Raw.t => t;

  // This function will prepare your data for sending it back to the server.
  // Depending on your graphql client library, this process should happen automatically for you.
  let serialize: t => Raw.t;

  // The definition tuple is primarily used to interact with client libraries.
  // The types are equivalent to: (parse, query, serialize).
  // Your client library will use these values to provide the properly parsed / serialized data for you.
  let definition: (
    Raw.t => t,
    string,
    t => Raw.t
  );

  // This is the representation of your raw result coming from the server.
  // It should not be necessary to access the types inside for normal use cases.
  module Raw: { type t; };
}
```*/
    let graphql_module: graphql_module = Obj.magic(0);
  };
};
module InlineFragmentQuery = {
  include InlineFragmentQuery';
  let self:
    module GraphQL_PPX.Query with
      type t_variables = InlineFragmentQuery'.t_variables and
      type Raw.t_variables = InlineFragmentQuery'.Raw.t_variables and
      type t = InlineFragmentQuery'.t and
      type Raw.t = InlineFragmentQuery'.Raw.t =
    (module InlineFragmentQuery');
};
module UnionExternalFragmentQuery = {
  module DogFragment' = {
    let query = "fragment DogFragment on Dog   {\nname  \nbarkVolume  \n}\n";
    module Raw = {
      type t = {
        .
        "name": string,
        "barkVolume": float,
      };
      type nonrec t_Dog = t;
    };
    type t = {
      name: string,
      barkVolume: float,
    };
    type nonrec t_Dog = t;
    let parse = (value: Raw.t): t => {
      let barkVolume = {
        let value = value##barkVolume;
        value;
      }
      and name = {
        let value = value##name;
        value;
      };
      {name, barkVolume};
    };
    let serialize: t => Raw.t =
      value => {
        let barkVolume = {
          let value = (value: t).barkVolume;
          value;
        }
        and name = {
          let value = (value: t).name;
          value;
        };
        {"name": name, "barkVolume": barkVolume};
      };
    let name = "DogFragment";
    module Z__INTERNAL = {
      type root = t;
      type nonrec graphql;
      /**```
Dog {
  name: String!
  barkVolume: Float!
}
```*/
      let graphql: graphql = Obj.magic(0);
      type nonrec graphql_module;
      /****--- GraphQL PPX Module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module UnionExternalFragmentQuery {
  // This is the stringified representation of your query, which gets sent to the server.
  let query: string;

  // This is the main type of the result you will get back.
  // You can hover above the identifier key (e.g. query or mutation) to see the fully generated type for your module.
  type t;

  // This function turns your raw result from the server into the reason/ocaml representation of that result.
  // Depending on your graphql client library, this process should happen automatically for you.
  let parse: Raw.t => t;

  // This function will prepare your data for sending it back to the server.
  // Depending on your graphql client library, this process should happen automatically for you.
  let serialize: t => Raw.t;

  // The definition tuple is primarily used to interact with client libraries.
  // The types are equivalent to: (parse, query, serialize).
  // Your client library will use these values to provide the properly parsed / serialized data for you.
  let definition: (
    Raw.t => t,
    string,
    t => Raw.t
  );

  // This is the representation of your raw result coming from the server.
  // It should not be necessary to access the types inside for normal use cases.
  module Raw: { type t; };
}
```*/
      let graphql_module: graphql_module = Obj.magic(0);
    };
  };
  module DogFragment = {
    include DogFragment';
    let self:
      module GraphQL_PPX.Fragment with
        type t = DogFragment'.t and type Raw.t = DogFragment'.Raw.t =
      (module DogFragment');
  };
  module Untitled1' = {
    module Raw = {
      type t_dogOrHuman;
      type t = {. "dogOrHuman": t_dogOrHuman};
      type t_variables = Js.Json.t;
    };
    let query =
      (
        (
          "query   {\ndogOrHuman  {\n__typename\n...on Dog   {\n..."
          ++ DogFragment.name
        )
        ++ "   \n}\n\n}\n\n}\n"
      )
      ++ DogFragment.query;
    type t_dogOrHuman = [
      | `FutureAddedValue(Js.Json.t)
      | `Dog(DogFragment.t)
    ];
    type t = {. "dogOrHuman": t_dogOrHuman};
    type t_variables = Js.Json.t;
    let parse: Raw.t => t =
      value => {
        let dogOrHuman = {
          let value = value##dogOrHuman;
          let typename: string =
            Obj.magic(Js.Dict.unsafeGet(Obj.magic(value), "__typename"));
          (
            switch (typename) {
            | "Dog" =>
              `Dog(
                {
                  let value: DogFragment.Raw.t = Obj.magic(value);
                  DogFragment.parse(value);
                },
              )
            | _ => `FutureAddedValue(Obj.magic(value): Js.Json.t)
            }: t_dogOrHuman
          );
        };
        {"dogOrHuman": dogOrHuman};
      };
    let serialize: t => Raw.t =
      value => {
        let dogOrHuman = {
          let value = value##dogOrHuman;
          switch (value) {
          | `Dog(value) => (
              Obj.magic(DogFragment.serialize(value)): Raw.t_dogOrHuman
            )
          | `FutureAddedValue(value) => (Obj.magic(value): Raw.t_dogOrHuman)
          };
        };
        {"dogOrHuman": dogOrHuman};
      };
    let make = () => {
      "query": query,
      "variables": Js.Json.null,
      "parse": parse,
    };
    module Z__INTERNAL = {
      type root = t;
      type nonrec graphql_module;
      /****--- GraphQL PPX Module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module UnionExternalFragmentQuery {
  // This is the stringified representation of your query, which gets sent to the server.
  let query: string;

  // This is the main type of the result you will get back.
  // You can hover above the identifier key (e.g. query or mutation) to see the fully generated type for your module.
  type t;

  // This function turns your raw result from the server into the reason/ocaml representation of that result.
  // Depending on your graphql client library, this process should happen automatically for you.
  let parse: Raw.t => t;

  // This function will prepare your data for sending it back to the server.
  // Depending on your graphql client library, this process should happen automatically for you.
  let serialize: t => Raw.t;

  // The definition tuple is primarily used to interact with client libraries.
  // The types are equivalent to: (parse, query, serialize).
  // Your client library will use these values to provide the properly parsed / serialized data for you.
  let definition: (
    Raw.t => t,
    string,
    t => Raw.t
  );

  // This is the representation of your raw result coming from the server.
  // It should not be necessary to access the types inside for normal use cases.
  module Raw: { type t; };
}
```*/
      let graphql_module: graphql_module = Obj.magic(0);
    };
  };
  module Untitled1 = {
    include Untitled1';
    let self:
      module GraphQL_PPX.Query with
        type t_variables = Untitled1'.t_variables and
        type Raw.t_variables = Untitled1'.Raw.t_variables and
        type t = Untitled1'.t and
        type Raw.t = Untitled1'.Raw.t =
      (module Untitled1');
  };
};
