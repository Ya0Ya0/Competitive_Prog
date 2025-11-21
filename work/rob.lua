-- Stable version of NeonAura (billgui+checker+team+health+distance) with dynamic StudsOffset, adjusted size, white background, black text color, and spacing between text labels

local localPlayer = game.Players.LocalPlayer

local function calculateDistance(player)
    local playerPos = player.Character and player.Character:FindFirstChild("HumanoidRootPart") and player.Character.HumanoidRootPart.Position
    local localPlayerPos = localPlayer.Character and localPlayer.Character:FindFirstChild("HumanoidRootPart") and localPlayer.Character.HumanoidRootPart.Position

    if playerPos and localPlayerPos then
        return (playerPos - localPlayerPos).Magnitude
    else
        return nil
    end
end

local function createBillboardGui(player)
    if player.Character and player.Character:FindFirstChild("HumanoidRootPart") then
        local humanoidRootPart = player.Character:FindFirstChild("HumanoidRootPart")

        -- Check if player already has a BillboardGui
        local existingBillboardGui = humanoidRootPart:FindFirstChildOfClass("BillboardGui")
        if existingBillboardGui then
            return -- Player already has a BillboardGui, do nothing
        end

        -- Create new BillboardGui
        local billboardGui = Instance.new("BillboardGui")
        billboardGui.Adornee = humanoidRootPart
        billboardGui.Size = UDim2.new(0, 50, 0, 40) -- Adjusted size to be 2 times smaller
        billboardGui.StudsOffset = Vector3.new(0, 3, 0)
        billboardGui.AlwaysOnTop = true

        local textLabel = Instance.new("TextLabel")
        textLabel.Size = UDim2.new(1, 0, 0.35, 0)
        textLabel.Position = UDim2.new(0, 0, 0, 0)
        textLabel.BackgroundTransparency = 0 -- Make the background visible
        textLabel.BackgroundColor3 = Color3.new(1, 1, 1) -- Set background color to white
        textLabel.Text = player.Name
        textLabel.TextColor3 = Color3.new(0, 0, 0) -- Set text color to black
        textLabel.TextScaled = true
        textLabel.Parent = billboardGui

        local healthLabel = Instance.new("TextLabel")
        healthLabel.Size = UDim2.new(1, 0, 0.3, 0)
        healthLabel.Position = UDim2.new(0, 0, 0.35, 0)
        healthLabel.BackgroundTransparency = 0 -- Make the background visible
        healthLabel.BackgroundColor3 = Color3.new(1, 1, 1) -- Set background color to white
        healthLabel.Text = "Health: " .. tostring(player.Character.Humanoid.Health)
        healthLabel.TextScaled = true
        healthLabel.TextColor3 = Color3.new(0, 0, 0) -- Set text color to black
        healthLabel.Parent = billboardGui

        -- Check if player is on a team
        local team = player.Team
        if team then
            local teamNameLabel = Instance.new("TextLabel")
            teamNameLabel.Size = UDim2.new(1, 0, 0.3, 0)
            teamNameLabel.Position = UDim2.new(0, 0, 0.7, 0)
            teamNameLabel.BackgroundTransparency = 0 -- Make the background visible
            teamNameLabel.BackgroundColor3 = Color3.new(1, 1, 1) -- Set background color to white
            teamNameLabel.Text = "Team: " .. team.Name
            teamNameLabel.TextScaled = true
            teamNameLabel.TextColor3 = Color3.new(0, 0, 0) -- Set text color to black
            teamNameLabel.Parent = billboardGui
        end

        -- Parent the BillboardGui to the Adornee's parent (to avoid clipping issues)
        billboardGui.Parent = humanoidRootPart.Parent
    end
end

local function removeBillboardGui(player)
    if player.Character then
        local humanoidRootPart = player.Character:FindFirstChild("HumanoidRootPart")
        if humanoidRootPart then
            local existingBillboardGui = humanoidRootPart:FindFirstChildOfClass("BillboardGui")
            if existingBillboardGui then
                existingBillboardGui:Destroy()
            end
        end
    end
end

local function updateBillboardGuis()
    for _, player in ipairs(game.Players:GetPlayers()) do
        createBillboardGui(player)
    end
end

game.Players.PlayerAdded:Connect(function(player)
    -- Create BillboardGui for new player
    createBillboardGui(player)

    player.CharacterAdded:Connect(function(character)
        -- Wait for a short delay to ensure character fully loads after respawn
        wait(1)
        if player.Character then
            -- Create BillboardGui when player's character is added (e.g., after respawn)
            createBillboardGui(player)
        end
    end)
end)

game.Players.PlayerRemoving:Connect(function(player)
    -- Remove BillboardGui when player leaves
    removeBillboardGui(player)
end)

-- Update BillboardGuis periodically
while true do
    updateBillboardGuis()
    wait(1) -- Adjust the interval as needed
end