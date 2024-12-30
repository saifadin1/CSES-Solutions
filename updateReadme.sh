#!/bin/bash

# Define the README file location
README="README.md"

# Array of topics and the total number of problems in each topic
declare -A topics=( 
    ["Introductory Problems"]="19"
    ["Sorting and Searching"]="35"
    ["Dynamic Programming"]="19"
    ["Graph Algorithms"]="36"
    ["Range Queries"]="19"
    ["Tree Algorithms"]="16"
    ["Mathematics"]="31"
    ["String Algorithms"]="17"
    ["Geometry"]="7"
    ["Advanced Techniques"]="24"
    ["Additional Problems"]="77"
)

# Function to update the README file
update_readme() {
    local topic=$1
    local solved=$2
    local total=$3

    # Calculate progress percentage (avoid division by zero)
    if (( total > 0 )); then
        local progress=$(( (solved * 100) / total ))
    else
        local progress=0
    fi

    # Return the formatted string that will be written to the README
    echo "| $topic | $solved/$total | ![](https://geps.dev/progress/$progress) |"
}

# Start the README content with the header
readme_content="# CSES-Solutions\n\n## Tracking Progress with Problem Sets\n\n| Topic         | Number Solved | Progress                                  |\n|-----------------------|---------------|-------------------------------------------|\n"

# Declare an array to store topic names and their solved counts
declare -A solved_counts
topic_array=()

# Loop through each topic and calculate the number of solved problems
overall_solved=0
overall_total=0
for topic in "${!topics[@]}"; do
    total_problems=${topics[$topic]}

    # Check if directory exists for the topic
    if [ -d "$topic" ]; then
        solved_problems=$(find "$topic" -type f | wc -l)
    else
        solved_problems=0
    fi

    # Store the solved problem count and topic in an array for sorting
    solved_counts["$topic"]=$solved_problems
    topic_array+=("$topic,$solved_problems")

    # Update overall counts
    overall_solved=$((overall_solved + solved_problems))
    overall_total=$((overall_total + total_problems))
done

# Sort the topic array based on the number of solved problems (in descending order)
IFS=$'\n' sorted_topics=($(sort -t',' -k2 -nr <<<"${topic_array[*]}"))
unset IFS

# Append the sorted topics to the README content
for topic_entry in "${sorted_topics[@]}"; do
    IFS=',' read -r topic solved_problems <<< "$topic_entry"
    total_problems=${topics[$topic]}
    
    # Append the topic progress to the README content
    readme_content+=$(update_readme "$topic" "$solved_problems" "$total_problems")$'\n'
done

# Update the overall progress
if (( overall_total > 0 )); then
    overall_progress=$(( (overall_solved * 100) / overall_total ))
else
    overall_progress=0
fi

# Append the overall progress to the README content
readme_content+="| overall               | $overall_solved/$overall_total | ![](https://geps.dev/progress/$overall_progress) |\n"

# Write the new content to the README file
echo -e "$readme_content" > "$README"

# Notify the user
echo "README updated successfully!"
