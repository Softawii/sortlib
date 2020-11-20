using DataFrames
using CSV
using Statistics
using Plots
using StatsPlots
using XLSX

path_pre = "./test"
path_folder = [
            "/results1",
            "/results2",
            "/results3"
            ]
path_file = [
            "/mergesort.csv", 
            "/bubblesort.csv", 
            "/quicksort.csv",
            "/selectionsort.csv",
            "/insertionsort.csv"
            ]


function CSVAverage(init_path::String, folders::Array{String, 1}, file::String)

    paths = String[] 

    # Definindo os paths #
    for folder in folders
        path = init_path * folder * file
        push!(paths, path)
    end

    # Pegando todos os CSVs e jogando em um único DataFrame
    sort_data = DataFrame.(CSV.File.(paths))

    # DataFrames filtrados
    random_data = DataFrame();
    ordered_data = DataFrame();
    reverse_data = DataFrame();

    # For para filtrar cada DataFrame pelo seu tipo
    for i in 1:length(sort_data)
        append!(random_data, filter(row -> row[:Type] == "random", sort_data[i]))

        append!(ordered_data, filter(row -> row[:Type] == "ordered", sort_data[i]))

        append!(reverse_data, filter(row -> row[:Type] == "reverse", sort_data[i]))
    end

    # Pegando todas as instancias 
    instances = unique(sort_data[1][:Instances])

    # DataFrame com a média do tempo de execução para cada tamanho de instancias
    avg_random = DataFrame();
    avg_ordered = DataFrame();
    avg_reverse = DataFrame();

    # Função para calcular a média das execuções
    for i in instances
        
        push!(avg_random, filter(row -> row[:Instances] == i, random_data)[1, :]);
        avg_random[end, :Time] = mean(filter(row -> row[:Instances] == i, random_data).Time)

        push!(avg_ordered, filter(row -> row[:Instances] == i, ordered_data)[1, :]);
        avg_ordered[end, :Time] = mean(filter(row -> row[:Instances] == i, ordered_data).Time)

        push!(avg_reverse, filter(row -> row[:Instances] == i, reverse_data)[1, :]);
        avg_reverse[end, :Time] = mean(filter(row -> row[:Instances] == i, reverse_data).Time)

    end

    return avg_random, avg_ordered, avg_reverse
end

function PlotData(Methods, Instances, Type::String)
    
    for i in Instances

        name = Type * "_" * string(i)

        dataFrame = DataFrame(Method = String[], Time = Float64[]);

        for method in Methods
            
            temp = filter(row -> row[:Instances] == i, method);
            
            if size(temp, 1) != 0

                
                temp = temp[1, :]
                
                push!(dataFrame, [temp.Method, temp.Time])   
            end
            
        end

        XLSX.writetable("results/$name.xlsx", collect(DataFrames.eachcol(dataFrame)), DataFrames.names(dataFrame))

    end
end


merge_random    , merge_ordered    , merge_reverse     = CSVAverage(path_pre, path_folder, path_file[1]);
bubble_random   , bubble_ordered   , bubble_reverse    = CSVAverage(path_pre, path_folder, path_file[2]);
quick_random    , quick_ordered    , quick_reverse     = CSVAverage(path_pre, path_folder, path_file[3]);
selection_random, selection_ordered, selection_reverse = CSVAverage(path_pre, path_folder, path_file[4]);
insertion_random, insertion_ordered, insertion_reverse = CSVAverage(path_pre, path_folder, path_file[5]);


Methods = [merge_random, bubble_random, quick_random, selection_random, insertion_random]
Instances = quick_random.Instances

PlotData(Methods, Instances, "Random") 


Methods = [merge_ordered, bubble_ordered, quick_ordered, selection_ordered, insertion_ordered]
Instances = quick_random.Instances

PlotData(Methods, Instances, "Ordered") 


Methods = [merge_reverse, bubble_reverse, quick_reverse, selection_reverse, insertion_reverse]
Instances = quick_random.Instances

PlotData(Methods, Instances, "Reverse") 

plot([string(i) for i in bubble_random.Instances] , bubble_random.Time, label="BubbleSort")
plot!([string(i) for i in selection_random.Instances] , selection_random.Time, label="SelectionSort")
plot!([string(i) for i in insertion_random.Instances] , insertion_random.Time, label="InsertionSort")
plot!([string(i) for i in quick_random.Instances] , quick_random.Time,  label="QuickSort")
plot!([string(i) for i in merge_random.Instances] , merge_random.Time,  label="MergeSort")



plot(["100", "200", "300"], [10, 20, 30])
