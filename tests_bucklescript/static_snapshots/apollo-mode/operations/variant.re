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
module MyQuery' = {
  module Raw = {
    type t_mutationForVariant_dog = {
      __typename: string,
      name: string,
      barkVolume: float,
    };
    type t_mutationForVariant_human = {
      __typename: string,
      name: string,
    };
    type t_mutationForVariant_dogOrHuman_Dog = {
      __typename: string,
      name: string,
      barkVolume: float,
    };
    type t_mutationForVariant_dogOrHuman_Human = {
      __typename: string,
      name: string,
    };
    type t_mutationForVariant_dogOrHuman;
    type t_mutationForVariant;
    type t = {mutationForVariant: t_mutationForVariant};
    type t_variables = Js.Json.t;
  };
  let query = "mutation   {\nmutationForVariant  {\nbaseType  \nbaseTypeList  \ndog  {\n__typename  \nname  \nbarkVolume  \n}\n\nhuman  {\n__typename  \nname  \n}\n\ndogOrHuman  {\n__typename\n...on Dog   {\n__typename  \nname  \nbarkVolume  \n}\n\n...on Human   {\n__typename  \nname  \n}\n\n}\n\n}\n\n}\n";
  type t_mutationForVariant_dog = {
    __typename: string,
    name: string,
    barkVolume: float,
  };
  type t_mutationForVariant_human = {
    __typename: string,
    name: string,
  };
  type t_mutationForVariant_dogOrHuman_Dog = {
    __typename: string,
    name: string,
    barkVolume: float,
  };
  type t_mutationForVariant_dogOrHuman_Human = {
    __typename: string,
    name: string,
  };
  type t_mutationForVariant_dogOrHuman = [
    | `FutureAddedValue(Js.Json.t)
    | `Dog(t_mutationForVariant_dogOrHuman_Dog)
    | `Human(t_mutationForVariant_dogOrHuman_Human)
  ];
  type t_mutationForVariant = [
    | `BaseType(string)
    | `BaseTypeList(array(string))
    | `Dog(t_mutationForVariant_dog)
    | `Human(t_mutationForVariant_human)
    | `DogOrHuman(t_mutationForVariant_dogOrHuman)
  ];
  type t = {mutationForVariant: t_mutationForVariant};
  type t_variables = Js.Json.t;
  let parse: Raw.t => t =
    (value) => (
      {
        mutationForVariant: {
          let value = (value: Raw.t).mutationForVariant;
          switch (Js.Json.decodeObject(Obj.magic(value): Js.Json.t)) {
          | None =>
            Js.Exn.raiseError(
              "graphql_ppx: "
              ++ "Expected type "
              ++ "VariantTestResult"
              ++ " to be an object",
            )
          | Some(value) =>
            let temp = Js.Dict.unsafeGet(Obj.magic(value), "baseType");
            switch (Js.Json.decodeNull(temp)) {
            | None =>
              let value = temp;
              `BaseType(value);
            | Some(_) =>
              let temp = Js.Dict.unsafeGet(Obj.magic(value), "baseTypeList");
              switch (Js.Json.decodeNull(temp)) {
              | None =>
                let value = temp;
                `BaseTypeList(value |> Js.Array.map(value => value));
              | Some(_) =>
                let temp = Js.Dict.unsafeGet(Obj.magic(value), "dog");
                switch (Js.Json.decodeNull(temp)) {
                | None =>
                  let value = temp;
                  `Dog(
                    {
                      __typename: {
                        let value =
                          (value: Raw.t_mutationForVariant_dog).__typename;
                        value;
                      },
                      name: {
                        let value = (value: Raw.t_mutationForVariant_dog).name;
                        value;
                      },
                      barkVolume: {
                        let value =
                          (value: Raw.t_mutationForVariant_dog).barkVolume;
                        value;
                      },
                    }: t_mutationForVariant_dog,
                  );
                | Some(_) =>
                  let temp = Js.Dict.unsafeGet(Obj.magic(value), "human");
                  switch (Js.Json.decodeNull(temp)) {
                  | None =>
                    let value = temp;
                    `Human(
                      {
                        __typename: {
                          let value =
                            (value: Raw.t_mutationForVariant_human).__typename;
                          value;
                        },
                        name: {
                          let value =
                            (value: Raw.t_mutationForVariant_human).name;
                          value;
                        },
                      }: t_mutationForVariant_human,
                    );
                  | Some(_) =>
                    let temp =
                      Js.Dict.unsafeGet(Obj.magic(value), "dogOrHuman");
                    switch (Js.Json.decodeNull(temp)) {
                    | None =>
                      let value = temp;
                      `DogOrHuman(
                        {
                          let typename: string =
                            Obj.magic(
                              Js.Dict.unsafeGet(
                                Obj.magic(value),
                                "__typename",
                              ),
                            );
                          (
                            switch (typename) {
                            | "Dog" =>
                              `Dog(
                                {
                                  let value: Raw.t_mutationForVariant_dogOrHuman_Dog =
                                    Obj.magic(value);
                                  (
                                    {
                                      __typename: {
                                        let value =
                                          (
                                            value: Raw.t_mutationForVariant_dogOrHuman_Dog
                                          ).
                                            __typename;
                                        value;
                                      },
                                      name: {
                                        let value =
                                          (
                                            value: Raw.t_mutationForVariant_dogOrHuman_Dog
                                          ).
                                            name;
                                        value;
                                      },
                                      barkVolume: {
                                        let value =
                                          (
                                            value: Raw.t_mutationForVariant_dogOrHuman_Dog
                                          ).
                                            barkVolume;
                                        value;
                                      },
                                    }: t_mutationForVariant_dogOrHuman_Dog
                                  );
                                },
                              )
                            | "Human" =>
                              `Human(
                                {
                                  let value: Raw.t_mutationForVariant_dogOrHuman_Human =
                                    Obj.magic(value);
                                  (
                                    {
                                      __typename: {
                                        let value =
                                          (
                                            value: Raw.t_mutationForVariant_dogOrHuman_Human
                                          ).
                                            __typename;
                                        value;
                                      },
                                      name: {
                                        let value =
                                          (
                                            value: Raw.t_mutationForVariant_dogOrHuman_Human
                                          ).
                                            name;
                                        value;
                                      },
                                    }: t_mutationForVariant_dogOrHuman_Human
                                  );
                                },
                              )
                            | _ =>
                              `FutureAddedValue(Obj.magic(value): Js.Json.t)
                            }: t_mutationForVariant_dogOrHuman
                          );
                        },
                      );
                    | Some(_) =>
                      Js.Exn.raiseError(
                        "graphql_ppx: "
                        ++ "All fields on variant selection set on type "
                        ++ "VariantTestResult"
                        ++ " were null",
                      )
                    };
                  };
                };
              };
            };
          };
        },
      }: t
    );
  let serialize: t => Raw.t =
    (value) => (
      {
        let mutationForVariant = {
          let value = (value: t).mutationForVariant;
          Obj.magic(Js.Json.null);
        };
        {mutationForVariant: mutationForVariant};
      }: Raw.t
    );
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
    module GraphQL_PPX.Mutation with
      type t_variables = MyQuery'.t_variables and
      type Raw.t_variables = MyQuery'.Raw.t_variables and
      type t = MyQuery'.t and
      type Raw.t = MyQuery'.Raw.t =
    (module MyQuery');
};
